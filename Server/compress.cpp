#include "compress.h"

int compress(unsigned char* output, unsigned char* input, int length) {  
	
	HashMapTable hash;
	SHA256 sha;
	unsigned char* chunk = (unsigned char*)malloc(MAX_CHUNK_SIZE*sizeof(unsigned char));
	int i=0;
	while(i < length){
		//split file into chunks
		unsigned size = chunking(input+i, chunk, length-i);
		i += size;
		printf ("Chunk size = \t%d\n", size);
		printf("First three characters of chunk:\t");
		printf("%c%c%c\n", *chunk, *(chunk+1), *(chunk+1));
	}
	return 0;
}
