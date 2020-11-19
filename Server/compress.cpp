#include "compress.h"

int compress(unsigned char* output, unsigned char* input, int length) {  
	
	HashMapTable hash;
	SHA256 sha;
	unsigned char* chunk = (unsigned char*)malloc(MAX_CHUNK_SIZE*sizeof(unsigned char));
	int i=0;
	while(i < length){
		//split file into chunks
		unsigned size = chunking(input+i, chunk, length-i);
		//for each chunk, calculate SHA-256
		// sha.update(chunk, size);
		// uint8_t* digest = sha.digest();
		// //deduplicate
		// if (hash.SearchKey(digest) == NULL) {
		// 	std::cout << "Match miss" << std::endl;
		// 	hash.Insert(digest, chunk);
		// 	lzw(chunk, output);
		   
		// } else {
		//    std::cout << "Match found" << std::endl;
		//    //write a 32b value
		// }
		i += size;
		printf ("Chunk size = \t%d\n", size);
		printf("First three characters of chunk:\t");
		printf("%c", *chunk);
		printf("%c", *(chunk+1));
		printf("%c", *(chunk+2));
		printf("\n");
		// std::cout << "chunk size = " << size << '\t';
		// std::cout << "Total size = " << i << std::endl;
		// delete[] digest;
	}

	return 0;
}
