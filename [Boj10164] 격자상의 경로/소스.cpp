#include <iostream>


using namespace std;

int n, m, k;
int dp[15 * 15 + 1];
int main()
{
	cin >> n >> m >> k;
	int ky = (k-1) / m;
	int kx = (k-1) % m;
	dp[0] = 1;
	for (int i = 1; i < n*m; i++)
	{
		int y = i / m;
		int x = i % m;
		if (y - 1 >= 0) dp[i] += dp[i - m];
		if (x - 1 >= 0) dp[i] += dp[i - 1];
	}
	int ay = n - ky - 1;
	int ax = m - kx - 1;
	if (k > 0) cout << dp[k - 1] * dp[ay*m + ax];
	else cout << dp[n*m - 1];
}