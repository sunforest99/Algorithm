#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[100001];
vector<int> vec[100001];
int answer[100001];
int num = 0;

void dfs(int start)
{
	if (visit[start]) return;
	visit[start] = true;
	num ++;
	answer[start] = num;
	for (int i = 0; i < vec[start].size(); i++)
	{
		int next = vec[start][i];
		dfs(next);
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

	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}