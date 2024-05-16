#include <iostream>
using namespace std;

int n;
int arr[9];

int visit[9];

void bt(int num)
{
	if (num == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[num] = i;
			bt(num + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> n;

	bt(0);

	return 0;
}