import os, inspect, errno
import tempfile
import re
import subprocess
import sys
import imp
import json

#windows platform specfic include
if re.match('^(linux|sunos)', sys.platform):
    windows = False
else:
    windows = True
    import cygpathHandler

#if running within QAF environment, include core scripts
qaf=None
qafDir = os.path.abspath(
    os.path.join(os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe()))), "..", "core_qaf"))
if os.path.exists (qafDir):
    if qafDir not in sys.path:
        sys.path.insert(0, qafDir)
    try:
        imp.find_module('qaf')
    except ImportError:
        sys.stderr.write ('Unable to locate "qaf" module. Exiting.\n')
        sys.exit(1)
    import qaf
else:
    class NonQAF:
        class Cip:
            def __init__(self, scriptFile):
                if scriptFile is not None:
                    self.currentFile = scriptFile

                if len(sys.argv) > 1:
                    self.cctFile = os.path.realpath (sys.argv[1])
                else:
                    sys.stderr.write ('ERROR: .cct file not specified. Exiting.\n')
                    sys.exit(1)

            def cctFilePath(self):
                """Return the pathname to the CCT file."""
                return self.cctFile

            def cctFileName(self):
                """Return the CCT filename."""
                return os.path.basename(self.cctFilePath())

            def exit_error(self, code, msg, cipFile=None):
                """Exit with a return code and option message. Any existing CIP will the closed and deleted """
                if cipFile is not None:
                    cipFile.close()
                    os.remove(cipFile.name)

                print ("ERROR: %s" % msg)
                sys.exit(code)

        def exit_error(self, code, cipFile=None):
            """Exit setting the error code and closing the CIP file if present."""
            if cipFile is not None:
                cipFile.close()
                os.remove(cipFile.name)

                sys.exit(code)

        class Cct:
            def __init__(self, cctFile):
                """Parse a CCT - throws if it cannot be read."""
                self.data = None
                self.body = []

                with open(cctFile) as file:
                    inHeader = True
                    headerString = ""
                    for line in file:
                        line = line.strip()
                        if line:
                            if inHeader and line[0] == '*':
                                headerString += line[1:]
                            else:
                                inHeader = False
                                self.body.append(line)
                        else:
                            inHeader = False

                self.data = json.loads(headerString)

            def header(self):
                """Return the JSON header of the CCT"""
                return self.data

            def body(self):
                """Return the CCT entries as a list"""
                return self.body

    qaf = NonQAF()


def processCommand(comCommand, tmpText):
    pCommand= comCommand
    try:
            f = open(tmpText, 'w')
            cmdProcess = subprocess.Popen(pCommand, stdin = subprocess.PIPE, stdout = f, stderr = subprocess.STDOUT)
            cmdProcess.communicate()
            f.close()
            if cmdProcess.returncode != 0:
                raise Exception("Command failed")
    except:
            assert False, "Failed to execute command '%s'" % pCommand

# Function to validate id compiler command is valid
def comandValidate(compilercmd):
   args = '-v'
   str = ' '
   seq = (compilercmd,args)
   cmd = str.join(seq)
   process = subprocess.Popen(cmd, shell=True, stdin = subprocess.PIPE, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
   process.communicate()
   exit_code = process.wait()
   return exit_code

#Function to get which binary
def whichComp(comExe):
    if comandValidate(comExe) == 0:
            return comExe

def mkdir_p(path):
    try:
        os.makedirs(path)
    except OSError as exc:  # Python >2.5
        if exc.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else:
            raise

def scanIncludePathForVersion(incPath):
    glibcxx_re = r'.*\\([0-9])\.([0-9])\.([0-9])\\include\\c\+\+' if windows else r'.*/include/c\+\+/([0-9])\.([0-9])\.([0-9])'
    prl_glibcxx = None
    match = re.match (glibcxx_re, incPath)
    if match:
        prl_glibcxx = { '__PRL_GLIBCXX__': match.group(1),
                        '__PRL_GLIBCXX_MINOR__': match.group(2),
                        '__PRL_GLIBCXX_PATCHLEVEL__': match.group(3) }
    return prl_glibcxx


# Search for System include and add them to cip file
def outCommand(dataDir,
               stubDir,
               fileName,
               systemIncludeOptionName,
               systemDefineOptionName,
               executableName,
               secondAlternativeExecutableName,
               thirdAlternativeExecutableName,
               additionalArgs,
               myCct):

    tmpDir = tempfile.gettempdir()
    tmpText = os.path.join (tmpDir, "QAtempCommFile.txt")
    tmpSrc = os.path.join (tmpDir, "QAtempTest.c")
    if not os.path.exists(tmpSrc):
        tfile = open(tmpSrc, 'w')
        tfile.close()

    cipFilename = os.path.splitext(fileName.strip())[0] + '.cip'
    cctDir = os.path.dirname(dataDir)
    configDir = os.path.dirname(cctDir)
    cipDir = os.path.join(configDir, "cip")
    mkdir_p (cipDir);
    cipFilePath = os.path.join(cipDir, cipFilename)

    # Check if Compiler Executable is available
    compiler = whichComp(executableName)
    if compiler is None:
        compiler = whichComp(secondAlternativeExecutableName)
        if compiler is None:
            compiler = whichComp(thirdAlternativeExecutableName)

    #if compiler executable not found then send error back to Framework
    if compiler is None:
        print ("* Error: Compiler Not Found \n* Please log a support request at www.perforce.com/support/request-support")
        if None != myCct:
            myCct.exit_error(1, "Compiler Not Found.\nPlease log a support request at www.perforce.com/support/request-support")
        else:
            return 1

    #if compiler executable found then continue
    commandLine = [ compiler, '-Wp,-v,-dM', '-E', tmpSrc ];
    if additionalArgs:
        commandLine.extend (additionalArgs)

    processCommand(commandLine, tmpText)

    try:
        with open(cipFilePath, 'w') as cipFile:
            forceIncludeList = []
            addedDirectories = []
            with open(tmpText) as compOutput:
                #
                # Hard coded Handling for
                #    o -forceinclude/-q forceinclude path
                #    o -i/-q stub_header_path
                #
                # QAF-1_0_5: To match prlgcc behavior, stub
                # directories are added based on the following
                # algorithm:
                #
                #   o A non empty top level Stub directory is added
                #     (eg. gcc)
                #
                #   o A nested directory that itself has children
                #     directories is added.
                #
                #   o Children of added parents won't themselves be
                #     added.
                #
                for dirName,dirnames,filenames in os.walk(stubDir, topdown=True):
                    if stubDir != dirName:
                        if dirName.endswith("prlforceinclude"):
                            cipFile.write('-q "%s"\n' % dirName)
                            for headerFile in filenames: # add all header files
                                forceIncludeList.append('-fi "%s"\n' % os.path.join(dirName, headerFile))
                        else:
                            shortName = dirName[len(stubDir):]
                            sepCount = shortName.count(os.sep)
                            addDirectory = False
                            if sepCount == 1 and len(filenames) != 0:
                                addDirectory = True
                            elif sepCount > 1 and len(dirnames) != 0:
                                addDirectory = True
                                for addedDirectory in addedDirectories:
                                    if shortName.startswith (addedDirectory):
                                        addDirectory = False

                            if addDirectory:
                                cipFile.write('-i "%s"\n' % dirName)
                                cipFile.write('-q "%s"\n' % dirName)
                                addedDirectories.append (shortName)

                forceIncludeList.sort()
                for i in forceIncludeList:
                    cipFile.write(i)

                prlify = []
                prl_glibcxx = None
                includes = False
                for line in compOutput.readlines():
                    line = line.strip()
                    if re.match(r'.*search starts here.$', line, re.IGNORECASE|re.U):
                            includes = True
                    elif re.match(r'^End of search list.$', line, re.IGNORECASE|re.U):
                            includes = False
                    elif includes:
                            incPath = os.path.normcase(line)
                            if windows:
                                if re.match(r'.*\\usr\\lib.*', incPath, re.IGNORECASE | re.U) or \
                                   re.match(r'.*\\usr\\include.*', incPath, re.IGNORECASE | re.U):
                                    incPath = cygpathHandler.ch_path(incPath)
                            cipFile.write('-%s "%s"\n' % (systemIncludeOptionName, incPath))
                            cipFile.write('-q  "%s"\n' % incPath)

                            if prl_glibcxx == None:
                                prl_glibcxx = scanIncludePathForVersion(incPath)


                    # Search for defines that help select path through headers
                    special_macros = [ '__GNUC_PATCHLEVEL__', '__GNUC_RH_RELEASE__' ]
                    for macro in special_macros:
                        m = re.match('#define\s*(%s)\s*([0-9]*)' % macro, line)
                        if m:
                            cipFile.write('\n* The detected %s.\n' % macro)
                            cipFile.write('-%s "%s=%s"\n' % (systemDefineOptionName, m.group(1), m.group(2)))

                    # Search for the __VERSION__ as part of creating the CIP
                    m = re.match(r'#define\s*(__VERSION__)\s+"(.*)"[^"]*$', line)
                    if m:
                        cipFile.write('\n* The detected __VERSION__ string.\n')
                        cipFile.write('-%s "%s=_PRL_STRINGIFY(%s)"\n' % (systemDefineOptionName, m.group(1), m.group(2)))

                    # Search for __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__ and __clang__
                    prlify_macros = ( '__GNUC__', '__GNUC_MINOR__',
                                      '__GNUC_PATCHLEVEL__', '__clang__' )
                    m = re.match('#define\s*([a-zA-Z_]\w*)\s*(\d+)\s*$', line)
                    if m and m.group(1) in prlify_macros:
                        prlify.append(m.group(1, 2))

                if prl_glibcxx != None:
                    cipFile.write('\n* The detected version of the GLIBCXX headers.\n');
                    for key in prl_glibcxx:
                        cipFile.write('-%s %s=%s\n' % ( systemDefineOptionName, key, prl_glibcxx[key]))

                if prlify:
                    cipFile.write('\n* The reported compiler version.\n')
                    for name, value in prlify:
                        cipFile.write('-%s "__PRL%s=%s"\n' % ( systemDefineOptionName, name[1:], value))

            compOutput.close()
            cipFile.close()
            return 0

    except Exception as e:
        if None != myCct:
            myCct.exit_error(2, "Error writing to %s: %s" % (cipFilePath, str(e)))
        return 2

def removeTemp():
    tmpDir = tempfile.gettempdir()
    tmpText = os.path.join (tmpDir, "QAtempCommFile.txt")
    tmpSrc= os.path.join (tmpDir, "QAtempTest.c")
    if os.path.exists(tmpText):
            os.remove(tmpText)
    if os.path.exists(tmpSrc):
            os.remove(tmpSrc)

def main(absScriptName,
     systemIncludeOptionName,
     systemDefineOptionName,
     executableName,
     alternativeExecutableName,
     additionalArgs):
    """
        systemIncludeOptionName - "i" for qac, "si" for qacpp
        systemDefineOptionName - "d" for qac, "sd" for qacpp
        executableName - e.g. "gcc"
        alternativeExecutableName - e.g. "gcc47"
        additionalArgs - e.g. "['-Wall']"
    """
    if not isinstance(additionalArgs, list):
        # Legacy scripts may still pass arguments as strings
        additionalArgs = additionalArgs.split()

    fileName = os.path.basename(absScriptName);
    cctName = os.path.splitext(fileName.strip())[0] + '.cct'

    dataDir = os.path.dirname (absScriptName)
    while os.path.basename (dataDir) != 'DATA':
        if dataDir == os.path.dirname (dataDir):
            raise Exception ("Script must be subdirectory of 'DATA'\n")
        dataDir = os.path.dirname (dataDir)

    stubDir = os.path.join (os.path.dirname (os.path.dirname (absScriptName)), "Stub")
    outCommand (dataDir,
                stubDir,
                fileName,
                systemIncludeOptionName,
                systemDefineOptionName,
                executableName,
                alternativeExecutableName,
                alternativeExecutableName,
                additionalArgs,
                None)
    removeTemp()
    sys.exit(0)


if __name__=="__main__":
    """
    Generate a CIP for GNU gcc/g++

    If debugging and running standalone ensure the first parameter is the full path to the CCT
    and the second is a pipe name - "stdout" or "stderr" will output any messages that would of
    been sent back to Framework to the console. Assuming you are in the common directory, under DATA then for example:

    python gnu_gcc.py "C:\sample_projects\Hello_C_CPP\prqa\configs\Initial\config\GNU_GCC-g++_4.7-x86_64-generic-linux-C++-c++11.cct" stderr

    Any non zero exit status indicates an error.
    """
    myCct = qaf.Cip(os.path.abspath(inspect.getfile(inspect.currentframe())))

    executableName=None
    version=None
    systemIncludeOptionName=None
    systemDefineOptionName=None

    dataDir=os.path.join (os.path.dirname (myCct.cctFilePath ()), 'DATA')
    stubDir=None

    cctFile = qaf.Cct (myCct.cctFilePath())
    cctContent = cctFile.header ()

    # Perform Sanity check that we've found all our variables
    for var in [ ('COMPILER_CMD', 'g++'), ('COMPILER_VERSION', '5.4'), ('SOURCE_LANGUAGE', 'C++') ]:
        if not var[0] in cctContent:
            myCct.exit_error(1, ("CCT missing entry for '%s', for example:\n* \"%s\": \"%s\"'." % (var[0], var[0], var[1])))

    executableName=cctContent['COMPILER_CMD']
    version=cctContent['COMPILER_VERSION']
    systemIncludeOptionName = "si" if cctContent['SOURCE_LANGUAGE'] == 'C++' else "i"
    systemDefineOptionName = "sd" if cctContent['SOURCE_LANGUAGE'] == 'C++' else "d"
    stubDir = os.path.join (os.path.join (dataDir, 'GNU_GCC-g++' if cctContent['SOURCE_LANGUAGE'] == 'C++' else 'GNU_GCC-gcc'), 'Stub')
    args=cctContent['COMPILER_ADDITIONAL_ARGS']

    secondAlternativeExecutableName=None
    thirdAlternativeExecutableName=None
    if executableName == 'g++' or executableName == 'gcc':
        # Special handling for g++ as we know the compiler naming scheme
        secondAlternativeExecutableName = executableName + version
        thirdAlternativeExecutableName = executableName + "-" + version

    result = outCommand(dataDir,
                        stubDir,
                        myCct.cctFileName (),
                        systemIncludeOptionName,
                        systemDefineOptionName,
                        executableName,
                        secondAlternativeExecutableName,
                        thirdAlternativeExecutableName,
                        args,
                        myCct)
    removeTemp()
    qaf.exit_error(result)
