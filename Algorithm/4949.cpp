#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    while (true)
    {
        string answer = "yes\n";
        string str;
        getline(cin, str);

        if (str == ".")
        {
            break;
        }

        stack<char> s;

        for (char elem : str)
        {
            if (elem == '(' || elem == '[')
            {
                s.push(elem);
            }
            else if (elem == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    answer = "no\n";
                    break;
                }
            }
            else if (elem == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    answer = "no\n";
                    break;
                }
            }
        }
        if (!s.empty())
        {
            answer = "no\n";
        }
        cout << answer;
    }
    return 0;
}