#!/bin/bash

set -e

#WORK_HOME="Script running : SecureImageGen Directory(./scripts/secure_img_gen_01.sh"

#ROOT KEY TYPE = 0x0(ROM fixed), 0x1(HashedPublickey), 0x2(HMACKEY)

ROOT_KEY_TYPE=0x00000001
ROLLBACK_COUNTER=0x00000001
ROOT_ECDSAKEY=../KeyGen/keys/ecdsa_privatekey.pem
ROOT_AESKEY=../KeyGen/keys/aes_rootkey.bin
ROOT_HMACKEY=0
ROOT_HASHGEN=0
ROOT_HASHOFPUBLICKEY=../KeyGen/keys/hash_of_publickey.bin

SIGN_TOOL=./tools/code_signer

INPUT_BASE=./img_plain
OUTPUT_BASE=./img_cipher

SRC_BIN=${INPUT_BASE}/sample_image_plain.bin
DST_BIN=${OUTPUT_BASE}/sample_image_cipher.bin

#code_signer <output_image> <bl_image(bin)> <signing key> <rootkey type> <rollback_counter> <hash_gen> <hashcode_of_publickey>
echo ${SIGN_TOOL} \
            ${DST_BIN}\
            ${SRC_BIN}\
            ${ROOT_ECDSAKEY}\
            ${ROOT_AESKEY}\
            ${ROOT_KEY_TYPE}\
            ${ROLLBACK_COUNTER}\
            ${ROOT_HASHGEN}\
            ${ROOT_HASHOFPUBLICKEY}

${SIGN_TOOL} \
            ${DST_BIN}\
            ${SRC_BIN}\
            ${ROOT_ECDSAKEY}\
            ${ROOT_AESKEY}\
            ${ROOT_KEY_TYPE}\
            ${ROLLBACK_COUNTER}\
            ${ROOT_HASHGEN}\
            ${ROOT_HASHOFPUBLICKEY}

