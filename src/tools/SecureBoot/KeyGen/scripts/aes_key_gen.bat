@echo off
SETLOCAL

rem WORK_HOME="Script running : KeyGen Directory(./scripts/aes_key_gen.bat)"

set KEY_DIR=..\keys
set TARGET_KEY=%KEY_DIR%\aes_rootkey.bin
set TOOL_BIN=..\tool\openssl$(EXEC)


@echo "---------------------"
@echo "Generate AES Key ..!!"
@echo "---------------------"

%TOOL_BIN% rand 32 > %TARGET_KEY%
