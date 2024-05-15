#include <iostream>
#include <cstring>
using namespace std;

char map[101][101];
int visit[101][101];

int xpos[] = { -1, 1, 0, 0 };
int ypos[] = { 0, 0, -1, 1 };

void dfs(int x, int y)
{
	if (visit[y][x]) return;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int addX = xpos[i] + x;
		int addY = ypos[i] + y;

		if (map[y][x] == map[addY][addX] && !visit[addY][addX])
		{
			dfs(addX, addY);
		}
	}
}

int main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				count++;
				dfs(j, i);
			}
		}
	}

	cout << count << " ";
	memset(visit, false, sizeof(visit));
	count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				count++;
				dfs(j, i);
			}
		}
	}
	cout << count;
}