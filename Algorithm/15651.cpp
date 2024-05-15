#include <iostream>
using namespace std;

int arr[9];
int visit[9];

int n, m;

void bt(int num)
{
	if (num == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		visit[i] = true;
		arr[num] = i;
		bt(num + 1);
		visit[i] = false;
	}
}

int main(void)
{
	cin >> n >> m;

	bt(0);

	return 0;
}