#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n = 0;
	queue<int> Queue;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		Queue.push(i);
	}

	while (Queue.size() != 1)
	{
		Queue.pop();
		int temp = Queue.front();
		Queue.pop();
		Queue.push(temp);
	}
	cout << Queue.front() << endl;

	return 0;
}
