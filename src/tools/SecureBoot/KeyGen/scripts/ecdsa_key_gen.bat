@echo off
SETLOCAL

rem WORK_HOME="Script running : KeyGen Directory(./scripts/ecdsa_key_gen.sh)"

set KEY_DIR=..\keys
set TARGET_KEY=%KEY_DIR%\ecdsa_privatekey.pem
set TARGET_HASH=%KEY_DIR%\hash_of_publickey.bin
set TOOL_BIN=..\tool\bin\openssl$(EXEC)
set TOOL_BIN2=..\SecureImgGen\tool\bin\code_signer
set TOOL_HEXDUMP=..\tool\hexdump$(EXEC)


echo "-------------------------------------"
echo "    Generate ECDSA Private Key !!    "
echo "-------------------------------------"
%TOOL_BIN% ecparam -genkey -name prime256v1 -out %TARGET_KEY%
%TOOL_BIN% ec -in %TARGET_KEY% -text -noout

echo "-------------------------------------"
echo " Generate Hash Code of Public Key !! "
echo "-------------------------------------"

%TOOL_BIN2% 0 0 %TARGET_KEY% 0 0 0 1 %TARGET_HASH
cat %TARGET_HASH%
echo ""
%TOOL_HEXDUMP%d %TARGET_HASH% 
