#include "compress.h"

int compress(chunk* output, unsigned char* input, int length) {
	

	int offset = 0;
	int chunk_num = 0;
	while(offset < length){
		//split file into chunks
		unsigned size = chunking(input + offset, (output + chunk_num)->chunk_data, length - offset);
		SHA256_CTX ctx;
		sha256(&ctx, (output + chunk_num)->chunk_data, (output + chunk_num)->chunk_hash, size);


		for (int i=0; i<SHA256_BLOCK_SIZE; i++)
		{
			printf("%02X", (output + chunk_num)->chunk_hash[i]);
		}
		printf("\n");
		offset += size;
		chunk_num ++;
	}
	return 0;
}