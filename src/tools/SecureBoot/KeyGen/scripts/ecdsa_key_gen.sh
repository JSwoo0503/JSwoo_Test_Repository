#!/bin/bash

set -e

#WORK_HOME="Script running : KeyGen Directory(./scripts/ecdsa_key_gen.sh)"
CUR_DIR=$(pwd)
KEY_DIR=${CUR_DIR}/keys
TARGET_KEY=${KEY_DIR}/ecdsa_privatekey.pem
TARGET_HASH=${KEY_DIR}/hash_of_publickey.bin
#TOOL_BIN=${CUR_DIR}/tool/bin/openssl
TOOL_BIN=openssl
TOOL_BIN2=../SecureImgGen/tools/code_signer


echo "-------------------------------------"
echo "    Generate ECDSA Private Key !!    "
echo "-------------------------------------"
${TOOL_BIN} ecparam -genkey -name prime256v1 -out ${TARGET_KEY}
${TOOL_BIN} ec -in ${TARGET_KEY} -text -noout

echo "-------------------------------------"
echo " Generate Hash Code of Public Key !! "
echo "-------------------------------------"
${TOOL_BIN2} 0 0 ${TARGET_KEY} 0 0 0 1 ${TARGET_HASH}
cat ${TARGET_HASH} 
echo ""
hd ${TARGET_HASH} 
