#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int visit[101][101];

int xpos[] = { -1, 1, 0,0 };
int ypos[] = { 0, 0, -1,1 };

vector<int> answer;

int height, width;

int dfsCount = 0;

void dfs(int x, int y)
{
	if (visit[y][x]) return;
	visit[y][x] = true;
	dfsCount++;

	for (int i = 0; i < 4; i++)
	{
		int addX = x + xpos[i];
		int addY = y + ypos[i];

		if (addX>= 0 && addX < width && addY >= 0 && addY < height && map[addY][addX] == 0)
		{
			dfs(addX, addY);
		}
	}
}

int main(void)
{
	int count;
	int rectCount = 0;

	cin >> height >> width >> count;

	for (int i = 0; i < count; i++)
	{
		int leftX, leftY, rightX, rightY;

		cin >> leftX >> leftY >> rightX >> rightY;

		for (int j = leftY; j < rightY; j++)
		{
			for (int k = leftX; k < rightX; k++)
			{
				map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!visit[i][j] && map[i][j] == 0)
			{
				dfsCount = 0;
				rectCount++;
				dfs(j, i);
				answer.push_back(dfsCount);
			}
		}
	}
	cout << rectCount << "\n";

	sort(answer.begin(), answer.end());
	for (int num : answer)
	{
		cout << num << " ";
	}

	return 0;
}