#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            int temp;
            cin >> temp;
            s.push(temp);
            break;
        case 2:
            if (!s.empty())
            {
                cout << s.top() << "\n";
                s.pop();
            }
            else
            {
                cout << "-1\n";
            }
            break;
        case 3:
            cout << s.size() << "\n";
            break;
        case 4:
            s.empty() ? cout << "1\n" : cout << "0\n";
            break;
        case 5:
            !s.empty() ? cout << s.top() << "\n" : cout << "-1\n";
            break;
        }
    }

    return 0;
}