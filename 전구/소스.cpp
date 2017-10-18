#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int dp[202][202][21];
int narr[202];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fill_n(&dp[0][0][0], 202 * 202 * 21, INF);
	for (int i = 1; i <= n; i++)
	{
		cin >> narr[i];
		dp[i][i][narr[i]] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (narr[i - 1] == j || narr[i + 1] == j) dp[i][i][j] = min(dp[i][i][j], 1);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i + 1; j++)
		{
			for (int c1 = 1; c1 <= k; c1++)
			{
				for (int c2 = 1; c2 <= k; c2++)
				{
					if (dp[j][j + i - 1][c1] != INF && dp[j + i][j + i][c2] != INF)
					{
						if (c1 == c2) dp[j][j + i][c1] = min(dp[j][j + i][c1], dp[j][j + i - 1][c1] + dp[j + i][j + i][c2]);
						else {
							dp[j][j + i][c1] = min(dp[j][j + i][c1], dp[j][j + i - 1][c1] + dp[j + i][j + i][c2] + 1);
							dp[j][j + i][c2] = min(dp[j][j + i][c2], dp[j][j + i - 1][c1] + dp[j + i][j + i][c2] + 1);
						}
					}
					if (dp[j][j][c1] != INF && dp[j + 1][j + i][c2] != INF)
					{
						if (c1 == c2) dp[j][j + i][c1] = min(dp[j][j + i][c1], dp[j][j][c1] + dp[j + 1][j + i][c2]);
						else {
							dp[j][j + i][c1] = min(dp[j][j + i][c1], dp[j][j][c1] + dp[j + 1][j + i][c2] + 1);
							dp[j][j + i][c2] = min(dp[j][j + i][c2], dp[j][j][c1] + dp[j + 1][j + i][c2] + 1);
						}
					}
				}
			}
		}
	}
	int ans = 987654321;
	for (int i = 1; i <= k; i++)
	{
		ans = min(ans, dp[1][n][i]);
	}
	cout << ans;
}