#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> Vector;
int n;
stack<int> Stack;
int Count = 1;

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		
		while (Count <= temp)
		{
			Vector.push_back('+');
			Stack.push(Count);
			Count++;
		}

		if (temp == Stack.top())
		{
			Vector.push_back('-');
			Stack.pop();
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (char Char : Vector)
	{
		cout << Char << "\n";
	}

	return 0;
}