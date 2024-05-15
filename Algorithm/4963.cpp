#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int map[51][51];
int visit[51][51];

int xpos[] = { -1 ,1 ,0 ,0 ,-1 ,1 ,1 ,-1 };
int ypos[] = { 0 ,0 ,-1 ,1 ,-1 ,-1 ,1 ,1 };

void dfs(int x, int y)
{
	if (visit[y][x]) return;
	visit[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int addX = x + xpos[i];
		int addY = y + ypos[i];

		if (map[addY][addX] == 1)
			dfs(addX, addY);
	}
}

int main(void)
{
	int n, m;
	int count = 0;

	while (true)
	{
		count = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					count++;
					dfs(j, i);
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}