#include <cstdlib>
#include <iostream>
#include <vector>
#include "sha.h"
#include "chunking.h"
#include "lzw.h"
#include "hash_table.h"

int compress(unsigned char* output, unsigned char* input, int length);