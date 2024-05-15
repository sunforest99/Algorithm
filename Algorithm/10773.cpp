#include <stack>
#include <iostream>
using namespace std;

int main(void)
{
    int n = 0;
    stack<int> s;
    int input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (input == 0)
        {
            s.pop();
        }
        else {

            s.push(input);
        }
    }

    int answer = 0;
    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    cout << answer;
    return 0;
}
