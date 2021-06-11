#!/bin/python 
from random import randint

#shellcode 
shellcode = "enter ur shellcode here!"
bad_chars = ["\x00"] #bad chars 

shellcode_ = bytearray()
shellcode_.extend(shellcode)

len_shellcode = len(shellcode_)
if len_shellcode % 2  == 1:  # checking if shellcode is aligned 
	shellcode_.append("\x90")


def encoder():
	encode_shellcode = bytearray()
	for i in range (0,len_shellcode,2):
		x = randint(1,255)	
		byte1 = shellcode_[i]
		byte2 = shellcode_[i+1]
		#XOR 
		byte1 = ( x ^ byte1 ) 
		byte2 = ( byte1 ^ byte2 )
		encode_shellcode.append(x)
		encode_shellcode.append(byte1)
		encode_shellcode.append(byte2)

	for i in bad_chars: #checking for bad chars 
		if encode_shellcode.find(i) >= 0 :
	#bad char found
			print "Illegal Char found , re-encoding wait :) "
			encoder()
	return encode_shellcode #Return the encoded shellcode


encoded_ = "" 
encoded_shellcode = encoder()
for y in encoded_shellcode:
	len_enc = len(str(hex(y)))
	if len_enc == 3 :
		encoded_+=str(hex(y)[:2])+"0"+str(hex(y)[2:])+","

	else:
		encoded_+=str(hex(y))+","

encoded_=encoded_[:-1]
print "Size of original shellcode is "+str(len(shellcode_))
print "Size of encoded shellcode is "+str(len(encoded_shellcode))
print encoded_	
