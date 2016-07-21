#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


int idx = 0;
string fn(string s)
{
	string ret;
	char currChar = s.substr(idx).at(0);
	if (currChar == 'w' || currChar == 'b')
	{
		ret = s.substr(idx).at(0);
		idx += 1;
	}
	else if (currChar == 'x')
	{
		ret = string("x");
		idx += 1;

		string subRet[4];
		for (int i = 0; i < 4; i++)
			subRet[i] = fn(s);
		ret += (subRet[2] + subRet[3] + subRet[0] + subRet[1]);
	}
	return ret;
}


int main(int argc, char* argv[])
{
	string s;
	int nTestCase;

	cin >> nTestCase;
	for (int testCase = 0; testCase < nTestCase; testCase++)
	{
		idx = 0;
		cin >> s;
		cout << fn(s) << endl;
	}

	return 0;
}
