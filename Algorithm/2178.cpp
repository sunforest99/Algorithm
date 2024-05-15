#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int inputX, inputY;
int map[101][101];
int visit[101][101];

int xdir[]{ -1,1,0,0 };
int ydir[]{ 0,0, -1,1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = 1;

	while (!q.empty())
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int addX = nowX + xdir[i];
			int addY = nowY + ydir[i];

			if (addX >= 0 && addX < inputX && addY >= 0 && addY < inputY && map[addY][addX] == 1 && visit[addY][addX] == 0)
			{
				visit[addY][addX] = visit[nowY][nowX] + 1;
				q.push(make_pair(addX, addY));
			}
		}
	}
}

int main(void)
{
	cin >> inputY >> inputX;

	for (int i = 0; i < inputY; i++)
	{
		for (int j = 0; j < inputX; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);

	cout << visit[inputY - 1][inputX - 1];

	return 0;
}