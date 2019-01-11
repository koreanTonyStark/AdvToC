/* Advanced Theory of Computation HW2
 * Student Name : Jeong Jae-Hwan
 * Student ID : 2018-26716
 * Brief : LZ78 decoding
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstddef>
#include <time.h>
#include "dTries.h"

#define JAEHWAN_DEBUG

/* Function : LZ78_decompress
 * Description : LZ78 Decoding  
 * Rules for better compression ratio, I used 2 MSB bits for recognizing the
 * number of block in one node number, so in first block get 1 byte, and
 * transform it to unsigned byte type and mask as 0x3F, 0011 1111 -> can
 * recongnize the number of blocks, then we can get the number of blocks
 * denoting the parse number ,and get one character for last character making
 * dictionary and decode other functions are commented in other files. 
 */
void LZ78_decompress(FILE *_after, FILE *_before)
{
	
	char c;
	Tries *dict = new Tries();
	uint8_t unsign_ch;
	int node_num;

	TriesNode *prevNode = nullptr;
	TriesNode *tempNode = dict->getRoot();

	while ( (c = fgetc(_after) ) != EOF)
	{
		unsign_ch = (uint8_t)c;
		int block_num = (unsign_ch >> 6);

		for (int i = 0; i <= block_num; ++i)
		{
			if (i == 0)
				node_num = unsign_ch & 0x3F;
			else
			{
				node_num = node_num << 8;
				node_num = node_num | unsign_ch;
			}
			c = fgetc(_after);
			unsign_ch = (uint8_t)c;
		}

		prevNode = dict->getTriesNode(node_num);
		dict->makeNode(prevNode, c);

		if (c == EOF)   
		{
			fprintf(_before, "%s", prevNode->getStr());
			break;
		}
		else
		{
			fprintf(_before, "%s%c", prevNode->getStr(), c);
		}

	}

}


/* Main function 
 * Description : Handling File I/O and execute LZ78_decompress function
 */
int main(int argc, char *argv[])
{
#ifndef JAEHWAN_DEBUG
	clock_t s,f;
	double time;
#endif


	if (argc != 3)
	{
		std::cerr << "Usage : ./decoding [target_file] [decompressed_file_name]";
		exit(-1);
	}

	FILE *after_LZ78 = fopen(argv[1], "r");
	FILE *before_LZ78 = fopen(argv[2], "w");
	
#ifndef JAEHWAN_DEBUG
	s = clock();
#endif
	LZ78_decompress(after_LZ78, before_LZ78);

#ifndef JAEHWAN_DEBUG
	f = clock();

	time = ((double)(f-s) / CLOCKS_PER_SEC);
	std::cout<<time<<std::endl;
#endif

	return 0;

}
