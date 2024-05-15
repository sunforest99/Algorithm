//1 2 3 4 5 6 7		// 3
// 1 2 4 5 7		// 6
//  1 4 5 7			// 2
//	 1 4 5			// 7
//	  1 4			// 5
//     4			// 1

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> Queue;
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		Queue.push(i);
	}

	cout << "<";
	while (!Queue.empty())
	{
		for (int i = 1; i < k; i++)
		{
			Queue.push(Queue.front());
			Queue.pop();
		}

		cout << Queue.front();
		if (Queue.size() != 1) cout << ", ";
		Queue.pop();
	}
	cout << ">";

	return 0;
}