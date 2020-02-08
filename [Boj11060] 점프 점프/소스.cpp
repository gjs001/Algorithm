#include <iostream>
#include <algorithm>
using namespace std;

int narr[1001];
int dp[1001];
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> narr[i];
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1000;
		for (int j = i - 100 > 0 ? i - 100 : 0  ; j < i; j++)
		{
			if(i-j <= narr[j])dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	if (dp[n - 1] == 1000) cout << -1;
	else cout << dp[n - 1];
}