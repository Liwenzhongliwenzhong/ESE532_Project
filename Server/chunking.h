#define WINDOW_LENGTH 3
#define MAX_CHUNK_SIZE 1000
#define WINDOW_HASH 65
#define N 255

#include <cstdint>
#include <cstring>

unsigned chunking(unsigned char* inputFile, unsigned char* chunkn, int length);
