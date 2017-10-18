#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Answer;
int h, w, k;
int map[13];

int check()
{
	for (int j = 0; j < w; j++)
	{
		int flag = 0;
		int cnt = 1;
		bool prev = (map[0] & 1 << (w - 1 - j));
		for (int i = 1; i < h; i++)
		{
			bool now = (map[i] & 1 << (w - 1 - j));
			if (prev == now) cnt++;
			else
			{
				cnt = 1;
			}
			if (cnt == k)
			{
				flag = 1;
				break;
			}
			prev = now;
		}
		if (!flag) return 0;
	}
	return 1;
}

void dfs(int now, int depth)
{
	if (depth >= Answer) return;
	if (check()) Answer = depth;
	for (int i = now; i < h; i++)
	{
		int tmp = map[i];

		map[i] = 0;
		dfs(i + 1, depth + 1);
		map[i] = (1 << w) - 1;
		dfs(i + 1, depth + 1);
		map[i] = tmp;
	}
}


int main()
{
	int T, test_case;
	ios::sync_with_stdio(false);
	cin.tie(0);



	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> h >> w >> k;
		Answer = k;
		for (int i = 0; i < h; i++)
		{
			int a = 0;
			for (int j = 0; j < w; j++)
			{
				int tmp;
				cin >> tmp;
				if (tmp) a |= 1 << (w - j - 1);
			}
			map[i] = a;
		}
		if (check()) Answer = 0;
		else
		{
			dfs(0,0);
		}
		cout << "#" << test_case + 1 << " " << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}