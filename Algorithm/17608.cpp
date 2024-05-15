#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int n = 0;
	stack<int> Stack;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		Stack.push(temp);
	}
	int Height = 0;
	while (!Stack.empty())
	{
		if (Stack.top() > Height)
		{
			Height = Stack.top();
			Stack.pop();
			answer++;
		}
		else
		{
			Stack.pop();
		}
	}

	cout << answer << endl;
	return 0;
}