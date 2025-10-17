#!/usr/bin/python
import binascii, sys, os

def byte_to_binary(n):
    return ''.join(str((n & (1<<i) and 1)) for i in reversed(range(8)))

def hex_to_binary(h):
    return ''.join(byte_to_binary(ord(b)) for b in binascii.unhexlify(h))

def binary_to_hex(b):
    return ''.join(hex(int(''.join(b[i:i+4]), 2))[2:] for i in range(0, len(b), 4))

def bin_to_hex_multi_byte(bytes, byte_len):
    return ''.join(binascii.b2a_hex(bytes[c]) for c in reversed(range(byte_len)))

if len(sys.argv) != 5:
    print ("Usage: bin_to_hex.py [Binary File] [Target Hex File] [Bit Length:num] [0/1:SD-for 4bit]")
    sys.exit(1)

frname = sys.argv[1]
hexname = sys.argv[2]
bitlen = int(sys.argv[3])
sd_mode = int(sys.argv[4])

if not os.path.isfile(frname):
    print ("- E - cannot read file !!")
    exit()
if not ((bitlen & 0x7) == 0):
    print ("- E - Bit Length only multiple 8 steps by byte size")
    exit()
frpath = os.path.dirname(os.path.abspath(frname))
frname = os.path.basename(frname)
fname, f_ext  = os.path.splitext(frname)
frname = frpath+'/'+frname
fwname = frpath+'/'+hexname+'.hex'

fr_fp = open(frname, 'rb')
fw_fp = open(fwname, 'w')

byte_len = bitlen / 8
bytes = fr_fp.read(byte_len)
while bytes != b'':
    hex_bytes = bin_to_hex_multi_byte(bytes, byte_len)
    #print hex_bytes
    if (sd_mode == 1):
            for i in range(8):
                fw_fp.write('0' + hex_bytes[i] + '\n')
    else:
        fw_fp.write(hex_bytes + '\n')
    bytes = fr_fp.read(byte_len)
    
fr_fp.close()
fw_fp.close()
