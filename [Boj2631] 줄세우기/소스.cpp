#include <iostream>
#include <algorithm>
using namespace std;

int n, narr[201];
int dp[201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> narr[i];
	int ans = 0;
	for (int i = 0; i < n; i++)	{
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if(narr[i] > narr[j])dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	cout << n - ans;
}