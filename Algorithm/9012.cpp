#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    string s;
    int n = 0;
    stack<char> stringstack;

    cin >> n;
    bool check = false;

    for (int i = 0; i < n; i++)
    {
        stringstack = {};
        cin >> s;

        for (char elem : s)
        {
            if (elem == '(')
            {
                stringstack.push(elem);
            }
            else
            {
                if (stringstack.empty())
                {
                    cout << "NO\n";
                    check = true;
                    break;
                }
                stringstack.pop();
            }
        }

        if (!check)
        {
            stringstack.empty() ? cout << "YES\n" : cout << "NO\n";
        }
        check = false;
    }

    return 0;
}