#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	queue<int> Queue;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str == "push")
		{
			int temp;
			cin >> temp;
			Queue.push(temp);
		}
		else if (str == "pop")
		{
			if (Queue.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Queue.front() << "\n";
				Queue.pop();
			}
		}
		else if (str == "size")
		{
			cout << Queue.size() << "\n";
		}
		else if (str == "empty")
		{
			Queue.empty() ? cout << "1\n" : cout << "0\n";
		}
		else if (str == "front")
		{
			!Queue.empty() ? cout << Queue.front() << "\n" : cout << "-1\n";
		}
		else if (str == "back")
		{
			!Queue.empty() ? cout << Queue.back() << "\n" : cout << "-1\n";
		}
	}

	return 0;
}