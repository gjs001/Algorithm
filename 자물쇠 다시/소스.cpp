#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, narr[101];
int dp[101][10][10];
int cnt[10] = { 0,1,1,1,2,2,2,1,1,1 };
int dfs(int cur, int s1, int s2)
{
	if (cur == n) return 0;
	int &ret = dp[cur][s1][s2];
	if (ret != -1) return ret;
	ret = 987654321;
	int cur_num = (narr[cur] + s1) % 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int add = cnt[i] + cnt[j] + cnt[(cur_num + i + j) % 10];
			if (add > 2) continue;
			ret = min(ret, dfs(cur + 1, (s2 + i + j) % 10, i) + add);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	char tmp[103];
	cin >> tmp;
	for (int i = 0; i < n; i++)
	{
		narr[i] = tmp[i] - '0';
	}
	cin >> tmp;
	for (int i = 0; i < n; i++)
	{
		narr[i] -= tmp[i] - '0';
		narr[i] = (narr[i] + 10) % 10;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0);
}