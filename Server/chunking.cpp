#include "chunking.h"

int8_t get_hash(unsigned char* window){
	int8_t hash = 0;
	//should be rolling
	for (int i=0; i< WINDOW_LENGTH; i++)
		hash += *(window+i) % N;
	
	return hash;
}



unsigned chunking(unsigned char* input, unsigned char* chunk, int length){
	unsigned char window[WINDOW_LENGTH];
	
    //Include window contents as beginning of chunk
    for (int i = 0; i < WINDOW_LENGTH; i++){
        window[i] = input[i+1];
    }
	chunk[0] = input[0];
	unsigned chunk_length = 1;
	if (get_hash(window) == WINDOW_HASH)
		return chunk_length;

	for (int i=1; i<length; i++){
		//append a byte into chunk
		chunk[i] = input[i];
		chunk_length++;
		//check if reach max length
		if (chunk_length >= MAX_CHUNK_SIZE)
			return MAX_CHUNK_SIZE;
		//update window
		for (int m=0; m< WINDOW_LENGTH-1; m++){
			window[m] = window[m+1];
		}
		window[WINDOW_LENGTH-1] = input[WINDOW_LENGTH+i];
		//compute hash
		if (get_hash(window) == WINDOW_HASH)
				return chunk_length;
	}
	
    return chunk_length;
}
