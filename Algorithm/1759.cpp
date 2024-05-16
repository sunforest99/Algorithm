#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<char> vec;
int visit[16];
char answer[16];

void bt(int num, int a)
{
	if (num == n)
	{
		int cnt = 0;
		int cnt1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u')
			{
				cnt++;
			}
			else
			{
				cnt1++;
			}
		}

		if (cnt >= 1 && cnt1 >= 2)
		{
			for (int i = 0; i < n; i++)
			{
				cout << answer[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = a; i < vec.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			answer[num] = vec[i];
			bt(num + 1, i);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		char chr;
		cin >> chr;
		vec.push_back(chr);
	}

	sort(vec.begin(), vec.end());
	bt(0, 0);

	return 0;
}