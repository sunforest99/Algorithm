#include <iostream>
#include <vector>
using namespace std;

char map[21][21];
int visit[26];
int width, height;

int xpos[] = { -1,1,0,0 };
int ypos[] = { 0,0,-1,1 };
int answer = 0;

void dfs(int x, int y, int cnt)
{
	if (cnt > answer)
	{
		answer = cnt;
	}

	for (int i = 0; i < 4; i++)
	{
		int addX = x + xpos[i];
		int addY = y + ypos[i];
		if (addX>=0 && addX< width && addY >= 0 && addY < height && !visit[map[addY][addX] - 'A'])
		{
			visit[map[addY][addX] - 'A'] = true;
			dfs(addX, addY, cnt + 1);
			visit[map[addY][addX] - 'A'] = false;
		}
	}
}

int main(void)
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}

	visit[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << answer;

	return 0;
}