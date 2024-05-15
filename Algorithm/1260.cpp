#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[1001];
bool visit[1001];
vector<int> bfsAnswer;
vector<int> dfsAnswer;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		bfsAnswer.push_back(now);
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (!visit[next])
			{
				q.push(next);
				visit[next] = true;
			}
		}
	}

}

void dfs(int start)
{
	if (visit[start]) return;
	visit[start] = true;
	dfsAnswer.push_back(start);
	for (int i = 0; i < vec[start].size(); i++)
	{
		int next = vec[start][i];
		dfs(next);
	}
}

int main(void)
{
	int n, m, v;

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);

	memset(visit, false, sizeof(visit));

	bfs(v);

	for (int n : dfsAnswer)
	{
		cout << n << " ";
	}
	cout << "\n";
	for (int n : bfsAnswer)
	{
		cout << n << " ";
	}

	return 0;
}