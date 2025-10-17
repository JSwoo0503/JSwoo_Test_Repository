#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/

#
# Common information
#
SECURE_DIR			:= $(ROOT_DIR)/tools/SecureBoot
KEYGEN_DIR			:= $(SECURE_DIR)/KeyGen
KEY_DIR				:= ${KEYGEN_DIR}/keys
CODE_SIGNER			:= ${SECURE_DIR}/SecureImgGen/tools/code_signer$(EXEC)

ifeq ($(UNAME), Linux)
OPENSSL				:= openssl
HEXDUMP				:= hexdump
else
OPENSSL				:= ${KEYGEN_DIR}/tools/openssl$(EXEC)
HEXDUMP				:= ${KEYGEN_DIR}/tools/hexdump$(EXEC)
endif




#
# Secure Key Genreation
#

# AES Key Generation
AES_TARGET_KEY		:= ${KEY_DIR}/aes_rootkey.bin
AES_KEY_GEN_CMD		:= ${OPENSSL} rand 32 > ${AES_TARGET_KEY}

# HMAC Key Generation
HMAC_TARGET_KEY		:= ${KEY_DIR}/hmac_rootkey.bin
HMAC_KEY_GEN_CMD	:= ${OPENSSL} rand 32 > ${HMAC_TARGET_KEY}

# ECDSA Key Generation
ECDSA_TARGET_KEY	:= ${KEY_DIR}/ecdsa_privatekey.pem
ECDSA_TARGET_HASH	:= ${KEY_DIR}/hash_of_publickey.bin
ECDSA_KEY_GEN_CMD	:= ${OPENSSL} ecparam -genkey -name prime256v1 -out ${ECDSA_TARGET_KEY}
ECDSA_KEY_VIEW_CMD	:= ${OPENSSL} ec -in ${ECDSA_TARGET_KEY} -text -noout
ECDSA_HASH_OF_PUBKEY := ${CODE_SIGNER} 0 0 ${ECDSA_TARGET_KEY} 0 0 0 1 ${ECDSA_TARGET_HASH}





#
# Secure Image Genreation
#

# ROOT KEY TYPE : 0x1(PUBKEY_DIGEST), 0x2(HMAC)
ROOT_KEY_HASHED_PUBKEY	:= 0x1
ROOT_KEY_HMAC			:= 0x2

ROLLBACK_COUNTER	:= 0x00000001
ROOT_ECDSAKEY		:= ${KEY_DIR}/ecdsa_privatekey.pem

ifeq ($(CMRT_KEY),1)
# Use case : For RT640_internal_OTP variation key
ROOT_AESKEY			:= ${KEY_DIR}/aes_rootkey.bin_derive
else
# Use case : For SYS_OTP AES Key(CMRT_KEY == 2)
ROOT_AESKEY			:= ${KEY_DIR}/aes_rootkey.bin
endif
ROOT_HMACKEY		:= ${KEY_DIR}/hmac_rootkey.bin
ROOT_HASHGEN		:= 0
ROOT_HASHOFPUBLICKEY := ${KEY_DIR}/hash_of_publickey.bin

SRC_BIN			:= $(OUTPUT)/$(BIN_NAME)
DST_BIN			:= $(OUTPUT)/$(BINPURE_NAME)_SECURE.bin

#code_signer <output_image> <bl_image(bin)> <signing key> <rootkey type> <rollback_counter> <hash_gen> <hashcode_of_publickey>

# ROOT_KEY_HASHED_PUBKEY
SECURE_IMG_GEN_CMD_HASHED_PUBKEY	:= ${CODE_SIGNER} ${DST_BIN} ${SRC_BIN} ${ROOT_ECDSAKEY} ${ROOT_AESKEY} ${ROOT_KEY_TYPE} ${ROLLBACK_COUNTER} ${ROOT_HASHGEN} ${ROOT_HASHOFPUBLICKEY}

# ROOT_KEY_HMAC
SECURE_IMG_GEN_CMD_HMAC	:= ${CODE_SIGNER} ${DST_BIN} ${SRC_BIN} ${ROOT_ECDSAKEY} ${ROOT_HMACKEY} ${ROOT_KEY_TYPE} ${ROLLBACK_COUNTER} ${ROOT_HASHGEN} ${ROOT_HASHOFPUBLICKEY}

# Bin2h
AWK_C := awk 'BEGIN { while( getline ) print "0x"$$0", " }'
AESKEY_2HEX := xxd -u -p -c 4 $(ROOT_AESKEY) | $(AWK_C) > $(ROOT_AESKEY).c
HMACKEY_2HEX := xxd -u -p -c 4 $(ROOT_HMACKEY) | $(AWK_C) > $(ROOT_HMACKEY).c
HASHOFPUBLICKEY_2HEX := xxd -u -p -c 4 $(ROOT_HASHOFPUBLICKEY) | $(AWK_C) > $(ROOT_HASHOFPUBLICKEY).c


#
# Script
#

secure_boot: secure_keygen
ifeq ($(BL_SEL),1)
	$(ECHO) "BL1 SECURE IMG ...     Skip"
else
# Check Secure boot enabled
ifeq ($(SECURE_BOOT),1)
	$(ECHO) ""
# Need Encrypted firmware?
ifeq ($(ROOT_KEY_TYPE),1)
	$(ECHO) "ROOT KEY TYPE ...      HASHED_PUBKEY"
	$(Q)$(SECURE_IMG_GEN_CMD_HASHED_PUBKEY) $(SUPPRESS_OUTPUT)
endif

ifeq ($(ROOT_KEY_TYPE),2)
	$(ECHO) "ROOT KEY TYPE ...      HMAC"
	$(Q)$(SECURE_IMG_GEN_CMD_HMAC) $(SUPPRESS_OUTPUT)
endif

	$(ECHO) "SECURE BOOT IMG ...    $(DST_BIN)"
endif
endif

secure_keygen:
# Check Secure boot enabled
ifeq ($(SECURE_BOOT),1)
	$(ECHO) ""
# Only the BL2 image can create secure images.
ifeq ($(BL_SEL),2)
# Need new keys?
ifeq ($(SECURE_KEY_GEN),1)

# Key Type : AES
	$(ECHO) "NEW KEY GEN ...        AES ($(AES_TARGET_KEY)"
	$(Q)$(AES_KEY_GEN_CMD)
	$(Q)$(AESKEY_2HEX)

# Key Type : HMAC
	$(ECHO) "NEW KEY GEN ...        HMAC ($(HMAC_TARGET_KEY))"
	$(Q)$(HMAC_KEY_GEN_CMD)
	$(Q)$(HMACKEY_2HEX)

# Key Type : ECDSA
	$(ECHO) "NEW KEY GEN ...        ECDSA ($(ECDSA_TARGET_KEY))"
	$(Q)$(ECDSA_KEY_GEN_CMD) $(SUPPRESS_OUTPUT)
	$(Q)$(ECDSA_KEY_VIEW_CMD) $(SUPPRESS_OUTPUT)

	$(ECHO) "NEW KEY GEN ...        HASH_OF_PUBKEY (${ECDSA_TARGET_HASH})"
	$(Q)$(ECDSA_HASH_OF_PUBKEY) $(SUPPRESS_OUTPUT)
	$(Q)$(HEXDUMP) ${ECDSA_TARGET_HASH}  $(SUPPRESS_OUTPUT)
	$(Q)$(HASHOFPUBLICKEY_2HEX)
else
	$(ECHO) "NEW KEY GEN ...        Skip"
endif
endif
endif

secure_keyinfo:
# Check Secure boot enabled
ifeq ($(SECURE_BOOT),1)
	$(ECHO) ""
	$(ECHO) "SECURE KYE INFO ..."
	$(ECHO) "AES : "
	$(Q)cat $(ROOT_AESKEY).hex

	$(ECHO) "HMAC : "
	$(Q)cat $(ROOT_HMACKEY).hex

	$(ECHO) "HASH OF PUBLICKEY : "
	$(Q)cat $(ROOT_HASHOFPUBLICKEY).hex
endif

