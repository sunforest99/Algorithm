#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int inputX, inputY;
int map[51][51];
int visit[51][51];

int xdir[] = { -1,1,0,0 };
int ydir[] = { 0,0, -1,1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;

	while (!q.empty())
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int addX = nowX + xdir[i];
			int addY = nowY + ydir[i];

			if (map[addY][addX] == 1 && !visit[addY][addX])
			{
				visit[addY][addX] = true;
				q.push(make_pair(addX, addY));
			}
		}
	}
}

int main(void)
{
	int answer = 0;
	int test_case;
	cin >> test_case;
	int line;
	for (int i = 0; i < test_case; i++)
	{
		answer = 0;
		cin >> inputX >> inputY >> line;
		for (int j = 0; j < line; j++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < inputY; i++)
		{
			for (int j = 0; j < inputX; j++)
			{
				if (!visit[i][j] && map[i][j] == 1)
				{
					bfs(j, i);
					answer++;
				}
			}
		}
		cout << answer << "\n";
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
	}

	return 0;
}