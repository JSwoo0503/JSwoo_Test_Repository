import sys
import re
import os
# Windows platform specific import
import _winreg as winreg

def getRegValue(keyName, valueName, sam=winreg.KEY_READ):
    reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
    key = winreg.OpenKey(reg, keyName, 0, sam)
    value = winreg.QueryValueEx(key, valueName)
    winreg.CloseKey(key)
    return value[0]

def get_cygpath():
    exists = True
    cygInstall =""
    try:
        cygInstall = getRegValue(r'SOFTWARE\Cygwin\setup','rootdir')
    except WindowsError:
        exists = False
    if not exists:
        try:
            cygInstall = getRegValue(r'SOFTWARE\Wow6432Node\Cygwin\setup','rootdir', (winreg.KEY_WOW64_64KEY + winreg.KEY_READ))
        except WindowsError:
            cygInstall = None
    return cygInstall

def ch_path(incPath):
    incPath = os.path.normcase(os.path.normpath(incPath))
    cygPath = get_cygpath()
    if not(cygPath == None) and not os.path.exists(incPath):
        if re.match(r'.*\\usr\\lib.*', incPath, re.IGNORECASE | re.U):
            replacePath = incPath.replace('usr\\lib','lib')
            incPath = cygPath + replacePath
        elif re.match(r'.*\\usr\\include.*', incPath, re.IGNORECASE | re.U):
            incPath = cygPath + incPath

    return incPath
