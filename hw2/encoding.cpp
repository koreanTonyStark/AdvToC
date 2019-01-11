/* Advanced Theory of Computation HW2 
 * Student Name : Jeong Jae Hwan
 * Student ID : 2018-26716
 * Brief : LZ78 Encoding  
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <time.h>
#include "Tries.h"

#define JAEHWAN_DEBUG

#define CHARACTER_SIZE 128


/* LZ78_compress(FILE, FILE)
 * Description : LZ78 Compression, used "Tries.h", "TriesNode.h" for
 * constructing trie(=dictionary), read a character 1 by 1, and make a node if
 * no such node exists, and also for better compression ratio, used 2 MSB bits
 * for storing parse number's information. first check whether it's in 2^6, if
 * it's not, then bit shift process will be added. another thing is same as the
 * decoding phase except the property to store the string information is not
 * needed in encoding phase. 
 */
void LZ78_compress(FILE *_before, FILE *_after)
{	
	Tries *dict = new Tries();
	char one_char;
	int node_num;

	while ( (one_char=fgetc(_before)) != EOF)
	{
		node_num = dict->makeNode(one_char);
		uint8_t ubyte[4];
		if (node_num != -1)
		{
			int i = 0;
			for (; i < 4; i++)
			{
				if (node_num < 64 )
				{
					ubyte[i] = i<<6 | node_num;
					break;
				}
				else
				{
					if(i>=3)
					{
						return;
					}
					ubyte[i] = node_num & 0xFF;
					node_num = node_num >> 8;
				}

			}
			for (; i >= 0; i--)
			{
				fprintf(_after, "%c", ubyte[i]);
			}
			fprintf(_after, "%c", one_char);  
		}
	}
	if (node_num == -1)
	{
		node_num =dict->getCurrentParseNum();
		int i = 0;
		uint8_t ubyte[4];
		for (; i < 4; i++) 
		{
			if (node_num <  64 ) 
			{
				ubyte[i] = (i << 6) | node_num;
				break;
			}
			else 
			{
				if (i >= 3) 
				{
					return;
				}
				ubyte[i] = node_num & 0xFF;
				node_num = node_num >> 8;
			}
		}
		for (; i >= 0; i--)
		{
			fprintf(_after, "%c", ubyte[i]);
		}
	}	
	return;
}

/* main function
 * Description : LZ78 Compression with FILE IO, used JAEHWAN_DEBUG macro for
 * evaluating the execution time of my algorithm. with encoding and decoding.
 */

int main(int argc, char *argv[])
{
#ifndef JAEHWAN_DEBUG
	clock_t s,f;
	double time;
#endif

	if (argc != 3)
	{
		std::cerr << "Usage : ./encoding [target_file] [after_compression]\n";
		exit(-1);
	}

	FILE *before_LZ78 = fopen(argv[1], "r");
	FILE *after_LZ78 = fopen(argv[2], "w");

	if (before_LZ78 == NULL)
	{
		std::cerr << "error : no such file exists\n";
		exit(-1);
	}

#ifndef JAEHWAN_DEBUG
	s=clock();
#endif
	LZ78_compress(before_LZ78, after_LZ78);

#ifndef JAEHWAN_DEBUG	
	f=clock();

	time = (   (double)(f-s)/CLOCKS_PER_SEC);
	std::cout<<time<<std::endl;
#endif
	
	fclose(before_LZ78);
	fclose(after_LZ78);

	return 0;

}

