#!/bin/bash

set -e

#WORK_HOME="Script running : KeyGen Directory(./scripts/aes_key_gen.sh)"
CUR_DIR=$(pwd)
KEY_DIR=${CUR_DIR}/keys
TARGET_KEY=${KEY_DIR}/aes_rootkey.bin
#TOOL_BIN=${CUR_DIR}/tool/bin/openssl
TOOL_BIN=openssl


echo "---------------------"
echo "Generate AES Key ..!!"
echo "---------------------"

${TOOL_BIN} rand 32 > ${TARGET_KEY}
