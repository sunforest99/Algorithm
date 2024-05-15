#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[101];
vector<int> vec[101];
int result;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (!visit[next])
			{
				q.push(next);
				result++;
				visit[next] = true;
			}
		}
	}
}

int main(void)
{
	int n;
	int a;
	cin >> a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	bfs(1);

	cout << result << endl;
	return 0;
}