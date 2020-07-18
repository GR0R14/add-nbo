#include <stdint.h> // uint32_t, uint16_t
#include <stdio.h>
#include <stdlib.h>//exit
#include <netinet/in.h> // ntohl

int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		exit(0);
	}

	FILE *fd_b[2] = {0, };

	for(int i=0; i<2; i++)
		fd_b[i] = fopen(argv[i+1], "rb");

	uint32_t b[2];
	uint32_t result;

	for(int i=0; i<2; i++){
		fread(&b[i], sizeof(uint32_t), 1, fd_b[i]);
		b[i] = ntohl(b[i]);
	}


	for(int i=0; i<2; i++)
		fclose(fd_b[i]);

	result = b[0] + b[1];

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", b[0], b[0], b[1], b[1], result, result);

	return 0;
}

