#include <iostream>
using namespace std;

int arr[9];
int visit[9];

int n, m;

void bt(int num, int a)
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

	for (int i = a; i <= n; i++)
	{
		visit[i] = true;
		arr[num] = i;
		bt(num + 1, i);
		visit[i] = false;
	}
}

int main(void)
{
	cin >> n >> m;

	bt(0, 1);

	return 0;
}