#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
int visit[9];
vector<int> vec;
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

	for (int i = 0; i < vec.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[num] = vec[i];
			bt(num + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> n >> m;

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	bt(0);

	return 0;
}