#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Program
{
public:
    Program()
    {
        stack = vector<char>();
    }

    void run()
    {
        int nTestCase;
        cin >> nTestCase;
        for (int i = 0; i < nTestCase; i++)
        {
            init();
            cin >> input;
            cout << solve() << endl;
        }
    }

    void init()
    {
        stack.clear();
        input.clear();
    }

    string solve()
    {
        for (int i = 0; i < input.length(); i++)
        {
            char curr = input.at(i);
            if (curr == ')' || curr == '}' || curr == ']')
            {
                if (stack.size() == 0)
                    return string("NO");

                if (curr == ')' && stack.back() == '(')
                    stack.pop_back();
                else if (curr == '}' && stack.back() == '{')
                    stack.pop_back();
                else if (curr == ']' && stack.back() == '[')
                    stack.pop_back();
                else
                    return string("NO");
            }
            else
            {
                stack.push_back(curr);
            }
        }
        if (stack.size() > 0)
            return string("NO");

        return string("YES");
    }

private:
    string input;
    vector<char> stack;
};


int main(int argc, char* argv[])
{
    Program prog;
    prog.run();

    return 0;
}