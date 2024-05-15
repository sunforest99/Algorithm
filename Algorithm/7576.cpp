#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];

int xpos[] = { -1, 1, 0,0 };
int ypos[] = { 0, 0, -1,1 };

int n, m;
int cnt;
int answer;

queue<pair<int, int>> q;
void bfs()
{
	while (!q.empty())
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{	
			int addX = nowX + xpos[i];
			int addY = nowY + ypos[i];

			if (addX >= 0 && addX < m && addY >= 0 && addY < n && map[addY][addX] == 0)
			{
				map[addY][addX] = map[nowY][nowX] + 1;
				q.push(make_pair(addX, addY));
			}
		}
	}
}

int main(void)
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				q.push(make_pair(j, i));
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (map[i][j] > answer)
			{
				answer = map[i][j];
			}
			if (map[i][j] == answer)
			{
				answer = map[i][j];
			}
		}
	}
	cout << answer - 1;

	return 0;
}