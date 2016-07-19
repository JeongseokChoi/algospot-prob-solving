#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using std::vector;
using std::min;

const int VERY_BIG_NUM = INT_MAX / 2;
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

vector<int> clockVec;


void pressSwitch(int switchNum)
// switchNum번 스위치를 한 번 누른다
{
	for (int i = 0; i < 16; i++)
	{
		clockVec[i] += switchArr[switchNum][i];
		clockVec[i] %= 12;
	}
}

bool chkDone()
{
	for (vector<int>::iterator i = clockVec.begin(); i != clockVec.end(); i++)
		if (*i != 0)
			return false;
	return true;
}

int search(int switchNum)
// switchNum(=depth) : 누른 스위치 번호
{
	if (switchNum >= 10)
	{
		if (chkDone())
			return 0;
		else
			return VERY_BIG_NUM;
	}

	int minimum = VERY_BIG_NUM;
	for (int i = 0; i < 4; i++)
	{
		minimum = min(minimum, i + search(switchNum + 1));
		pressSwitch(switchNum);
	}
	return minimum;
}


int main(int argc, char* argv[])
{
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

		int answer = search(0);
		printf("%d\n", answer < VERY_BIG_NUM? answer : -1);
	}
}
