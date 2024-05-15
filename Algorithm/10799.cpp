#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> Stack;
	string str;
	int answer = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			Stack.push(str[i]);
		}
		else
		{
			if (str[i - 1] == '(')
			{
				Stack.pop();
				answer += Stack.size();
			}
			else
			{
				answer++;
				Stack.pop();
			}
		}
	}

	cout << answer << endl;
	
	return 0;
}