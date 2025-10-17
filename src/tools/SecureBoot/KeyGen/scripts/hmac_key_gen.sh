#!/bin/bash

set -e

#WORK_HOME="Script running : KeyGen Directory(./scripts/hmac_key_gen.sh)"
CUR_DIR=$(pwd)
KEY_DIR=${CUR_DIR}/keys
TARGET_KEY=${KEY_DIR}/hmac_rootkey.bin
#TOOL_BIN=${CUR_DIR}/tool/bin/openssl
TOOL_BIN=openssl


echo "---------------------"
echo "Generate HMAC Key ..!!"
echo "---------------------"

${TOOL_BIN} rand 32 > ${TARGET_KEY}
