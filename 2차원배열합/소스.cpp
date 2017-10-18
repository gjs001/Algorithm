#include <iostream>

using namespace std;


int narr[301][301];
int dp[301][301];
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> narr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + narr[i][j] - dp[i-1][j-1];
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b, y, x;
		cin >> a >> b >> y >> x;
		cout << dp[y][x] + dp[a - 1][b - 1] - dp[a-1][x] - dp[y][b-1] << "\n";
	}
}