#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SZ 101


char plainText[BUF_SZ];
char cipherText[BUF_SZ];


int main(int argc, char *argv[])
{
	int nCase;

	scanf("%d", &nCase);
	while (nCase--)
	{
		memset(plainText, 0, BUF_SZ * sizeof(char));
		memset(cipherText, 0, BUF_SZ * sizeof(char));

		scanf("%s", plainText);
		int len = strlen(plainText);
		int cnt = 0;
		for (int i = 0; i < len; i += 2)
			cipherText[cnt++] = plainText[i];
		for (int i = 1; i < len; i += 2)
			cipherText[cnt++] = plainText[i];

		printf("%s\n", cipherText);
	}

	return 0;
}