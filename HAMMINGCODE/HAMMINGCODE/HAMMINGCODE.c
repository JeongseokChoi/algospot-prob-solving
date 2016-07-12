#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int nCase;
	char msg[8];
	
	scanf("%d", &nCase);
	while (nCase--)
	{
		memset(msg, 0, sizeof(msg));
		scanf("%s", msg);

		int errBit = 0;

		// check 3
		if (msg[3] ^ msg[4] ^ msg[5] ^ msg[6])
			++errBit;
		
		errBit <<= 1;

		// check 2
		if (msg[1] ^ msg[2] ^ msg[5] ^ msg[6])
			++errBit;

		errBit <<= 1;

		// check 1
		if (msg[0] ^ msg[2] ^ msg[4] ^ msg[6])
			++errBit;

		if (errBit)
			msg[errBit - 1] = msg[errBit - 1] == '1' ? '0' : '1';

		printf("%c%c%c%c\n", msg[2], msg[4], msg[5], msg[6]);
	}

	return 0;
}