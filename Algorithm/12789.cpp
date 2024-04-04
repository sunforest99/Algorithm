#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> Line;
	int input;
	int n = 0;
	int count = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input != count)
		{
			Line.push(input);
		}
		else
		{
			count++;
		}

		while (!Line.empty() && Line.top() == count)
		{
			Line.pop();
			count++;
		}
	}

	Line.empty() ? cout << "Nice" : cout << "Sad";
	return 0;
}