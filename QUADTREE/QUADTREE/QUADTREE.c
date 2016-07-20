#include <stdio.h>
#include <stdlib.h>
#include <string.h>





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
