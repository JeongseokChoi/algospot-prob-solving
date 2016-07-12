#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int main(int argc, char *argv[])
{
	int nCase;
	scanf("%d", &nCase);

	while (nCase--)
	{
		unsigned int *input = (unsigned int *)malloc(sizeof(unsigned int));
		unsigned int *output = (unsigned int *)malloc(sizeof(unsigned int));
		
		memset(input, 0, sizeof(unsigned int));
		memset(output, 0, sizeof(unsigned int));
		
		scanf("%u", input);
		memcpy((char *)output, (char *)input + 3, 1);
		memcpy((char *)output + 1, (char *)input + 2, 1);
		memcpy((char *)output + 2, (char *)input + 1, 1);
		memcpy((char *)output + 3, (char *)input, 1);

		printf("%u\n", *(unsigned int *)output);

		free(input);
		free(output);
	}

	return 0;
}
