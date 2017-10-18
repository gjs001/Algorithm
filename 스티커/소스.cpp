#include <iostream>
#include <algorithm>
using namespace std;

int narr[2][100001];
int dp[2][100001];
int t, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> narr[i][j];
			}
		}
		dp[0][1] = narr[0][1];
		dp[1][1] = narr[1][1];
		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1] + narr[0][i], dp[1][i - 2] + narr[0][i]);
			dp[1][i] = max(dp[0][i - 1] + narr[1][i], dp[0][i - 2] + narr[1][i]);
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}