#include <iostream>
#include <queue>
using namespace std;

vector<int> vec[101];
int visit[101];

int findn, findm;
int n, m, p, list;

int cont = 1;
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			
			if (visit[next] == 0)
			{
				visit[next] = visit[now] + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	cin >> p;
	cin >> findn >> findm;
	cin >> list;

	for (int i = 0; i < list; i++)
	{
		cin >> n >> m;
		vec[n].push_back(m);
		vec[m].push_back(n);
	}

	bfs(findn);

	if (visit[findm] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << visit[findm] - 1;
	}

	return 0;
}