#include <iostream>
using namespace std;

char map[101][101];
bool visit[101][101];

int xpos[] = { -1, 1, 0,0 };
int ypos[] = { 0,0,-1,1 };
int cont = 0;
int n, m;
int w, b;

void dfs(int x, int y)
{
	if (visit[y][x]) 
	{ return; }
	visit[y][x] = true;
	cont++;
	for (int i = 0; i < 4; i++)
	{
		int addX = xpos[i] + x;
		int addY = ypos[i] + y;
		if(addX >= 0 && addX < n && addY >=0 && addY < m && map[addY][addX] == map[y][x])
			dfs(addX, addY);
	}
}

int main(void)
{
	cin >> n >> m;
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
			if (!visit[i][j])
			{
				cont = 0;
				dfs(j, i);
				map[i][j] == 'W' ? w += cont * cont : b += cont * cont;
			}
		}
	}
	cout << w << " " << b << endl;

	return 0;
}