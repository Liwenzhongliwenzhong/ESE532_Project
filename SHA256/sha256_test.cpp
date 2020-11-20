/*********************************************************************
* Filename:   sha256.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Performs known-answer tests on the corresponding SHA1
	          implementation. These tests do not encompass the full
	          range of available test vectors, however, if the tests
	          pass it is very, very likely that the code is correct
	          and was compiled properly. This code also serves as
	          example usage of the functions.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
void sha256_test()
{
	BYTE text[] = {"abc"};

	BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	sha256(&ctx, text, buf, 3);
	for (int i=0; i<SHA256_BLOCK_SIZE; i++)
	{
		printf("%X", buf[i]);
	}
}

int main()
{
	sha256_test();
	return(0);
}
