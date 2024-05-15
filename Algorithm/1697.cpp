#include <iostream>
#include <queue>
using namespace std;

int visit[100001];

int n, k;

void bfs(int start)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visit[start] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int count = q.front().second;
		q.pop();

		if (now == k)
		{
			cout << count;
			break;
		}

		if (now - 1 >= 0 && now - 1 < 100001 && !visit[now - 1])
		{
			visit[now - 1] = true;
			q.push(make_pair(now - 1, count + 1));
		}

		if (now + 1 >= 0 && now + 1 < 100001 && !visit[now + 1])
		{
			visit[now + 1] = true;
			q.push(make_pair(now + 1, count + 1));
		}

		if (now * 2 >= 0 && now * 2 < 100001 && !visit[now * 2])
		{
			visit[now * 2] = true;
			q.push(make_pair(now * 2, count + 1));
		}
	}
}

int main(void)
{
	cin >> n >> k;
	bfs(n);
	return 0;
}