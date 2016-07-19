#include <iostream>
#include <vector>
#include <climits>
using std::vector;


const int switchArr[10][16] = 
{
	{ 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3 },
	{ 3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0 },
	{ 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0 }
};


int main(int argc, char* argv[])
{
	vector<int> clockVec;
	int nTestCase;

	scanf("%d", &nTestCase);
	for (int testCase = 0; testCase < nTestCase; testCase++)
	{
		clockVec.clear();
		clockVec.assign(16, 0);
		for (int i = 0; i < 16; i++)
		{
			scanf("%d", &clockVec[i]);
			clockVec[i] %= 12;
		}
	}
}
