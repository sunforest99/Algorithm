#include <iostream>
using namespace std;

int map[501][501];
int visit[501][501];

int xpos[] = { -1,1,0,0 };
int ypos[] = { 0,0,-1,1 };
int dfscount;
int answer;

void dfs(int x, int y)
{
	if (visit[y][x]) 
	{ 
		return;
	}

	visit[y][x] = true;
	dfscount++;

	for (int i = 0; i < 4; i++)
	{
		int addX = x + xpos[i];
		int addY = y + ypos[i];
		
		if (map[addY][addX] == 1)
		{
			dfs(addX, addY);
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int count = 0;
	answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				dfscount = 0;
				count++;
				dfs(j, i);
				if (dfscount > answer)
				{
					answer = dfscount;
				}
			}
		}
	}

	cout << count << "\n" << answer;
	
	return 0;
}