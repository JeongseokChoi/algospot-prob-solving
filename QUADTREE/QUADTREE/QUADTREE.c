#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node_t
{
    char data;
    struct Node_t* child[4];
} Node_t;


int main(int argc, char* argv[])
{
	char buf[1001];
	int nTestCase;

	fgets(buf, 1001, stdin);
	nTestCase = atoi(buf);
	for (int testCase = 0; testCase < nTestCase; testCase++)
	{
		fgets(buf, 1001, stdin);
		buf[strlen(buf) - 1] = '\0';


	}

	return 0;
}
