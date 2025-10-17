@echo off
SETLOCAL

rem WORK_HOME="Script running : KeyGen Directory(./scripts/hmac_key_gen.sh)"


set KEY_DIR=..\keys
set TARGET_KEY=%KEY_DIR%\hmac_rootkey.bin
set TOOL_BIN=..\tool\openssl$(EXEC)


echo "---------------------"
echo "Generate HMAC Key ..!!"
echo "---------------------"

%TOOL_BIN% rand 32 > %TARGET_KEY%
