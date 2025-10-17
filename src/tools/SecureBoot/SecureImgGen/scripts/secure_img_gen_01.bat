@echo off
SETLOCAL

rem WORK_HOME="Script running : SecureImageGen Directory(.\scripts\secure_img_gen_01.bat"
rem ROOT KEY TYPE = 0x0(ROM fixed), 0x1(HashedPublickey), 0x2(HMACKEY)

set ROOT_KEY_TYPE=0x00000001
set ROLLBACK_COUNTER=0x00000001
set ROOT_ECDSAKEY=../../KeyGen/keys/ecdsa_privatekey.pem
set ROOT_AESKEY=../../KeyGen/keys/aes_rootkey.bin
set ROOT_HMACKEY=0
set ROOT_HASHGEN=0
set ROOT_HASHOFPUBLICKEY=../../KeyGen/keys/hash_of_publickey.bin

set SIGN_TOOL=..\tool\code_signer$(EXEC)

set INPUT_BASE=../img_plain
set OUTPUT_BASE=../img_cipher

set SRC_BIN=%INPUT_BASE%/sample_image_plain.bin
set DST_BIN=%OUTPUT_BASE%/sample_image_cipher.bin

rem
rem code_signer <output_image> <bl_image(bin)> <signing key> <rootkey type> <rollback_counter> <hash_gen> <hashcode_of_publickey>
rem

echo %SIGN_TOOL% %DST_BIN% %SRC_BIN% %ROOT_ECDSAKEY% %ROOT_AESKEY%  %ROOT_KEY_TYPE% %ROLLBACK_COUNTER% %ROOT_HASHGEN% %ROOT_HASHOFPUBLICKEY%

%SIGN_TOOL% %DST_BIN% %SRC_BIN% %ROOT_ECDSAKEY% %ROOT_AESKEY%  %ROOT_KEY_TYPE% %ROLLBACK_COUNTER% %ROOT_HASHGEN% %ROOT_HASHOFPUBLICKEY%

pause
