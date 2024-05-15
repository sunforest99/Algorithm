#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool visit[1001];
int n, m;

void dfs(int start)
{
	if (visit[start]) return;
	visit[start] = true;

	for (int i = 0; i < vec[start].size(); i++)
	{
		dfs(vec[start][i]);
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if(!visit[i])
		{
			dfs(i);
			count++;
		}
	}

	cout << count;
}