#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[25][25];
int visit[25][25];

int xdir[] = { -1, 1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };

vector<int>	answer;
int input;

void bfs(int x, int y)
{
	int result = 1;
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

			if (addX >= 0 && addX < input && addY >= 0 && addY < input && map[addY][addX] == 1 && !visit[addY][addX])
			{
				visit[addY][addX] = true;
				q.push(make_pair(addX, addY));
				result++;
			}
		}
	}
	answer.push_back(result);
}

int main(void)
{
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (map[i][j] == 1 && !visit[i][j])
			{
				bfs(j, i);
			}
		}
	}
	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int num : answer)
	{
		cout << num << "\n";
	}

	return 0;
}