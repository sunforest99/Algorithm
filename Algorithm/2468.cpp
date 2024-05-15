#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101][101];

int xpos[] = { -1, 1, 0, 0 };
int ypos[] = { 0, 0, -1, 1 };

int n = 0;
int answer;

void dfs(int x, int y, int rain)
{
	if (visit[y][x]) return;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int addX = x + xpos[i];
		int addY = y + ypos[i];

		if (addX >= 0 && addX < n && addY >= 0 && addY < n && map[addY][addX] > rain)
		{
			dfs(addX, addY, rain);
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= 100; i++)
	{
		memset(visit, false, sizeof(visit));
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (map[j][k] > i && !visit[j][k])
				{
					dfs(k, j, i);
					count++;
				}
			}
		}

		if (count > answer)
		{
			answer = count;
		}
	}

	cout << answer;

	return 0;
}