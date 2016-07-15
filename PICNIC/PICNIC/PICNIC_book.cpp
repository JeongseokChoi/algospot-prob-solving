#include <iostream>
#include <cstring>
using namespace std;


int n;
bool areFriends[10][10];
bool taken[10];

int countPairings(bool taken[])
{
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1)
	{
		return 1;
	}

	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}


int main(int argc, char *argv[])
{
	int nTestCase;
	scanf("%d", &nTestCase);

	for (int testCase = 0; testCase < nTestCase; testCase++)
	{
		// initialize
		int nPair;
		n = nPair = 0;
		memset(taken, 0, sizeof(taken));
		memset(areFriends, 0, sizeof(areFriends));

		scanf("%d %d", &n, &nPair);
		for (int i = 0; i < nPair; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		
		printf("%d\n", countPairings(taken));
	}

	return 0;
}