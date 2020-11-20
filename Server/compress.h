#include <cstdlib>
#include <iostream>
#include <vector>
#include "sha.h"
#include "chunking.h"
#include "lzw.h"
#include "hash_table.h"

typedef struct {
	unsigned char chunk_data[MAX_CHUNK_SIZE];
    unsigned char chunk_hash[SHA256_BLOCK_SIZE];
	//LZW can also be stored here. See further implementation
} chunk;

int compress(chunk* output, unsigned char* input, int length);