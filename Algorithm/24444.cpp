#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[100001];
vector<int> vec[100001];
int answer[100001];

void bfs(int start)
{
	int temp = 1;
	queue<int> q;
	q.push(start);
	visit[start] = true;
	answer[start] = temp;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (!visit[next])
			{
				temp++;
				answer[next] = temp;
				q.push(next);
				visit[next] = true;
			}
		}
	}
}

int main(void)
{
	int n, m, r;
	cin >> n >> m >> r;

	int x, y;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}