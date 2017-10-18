#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;


int n, m;
int nArr[101];
int dp[10001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &nArr[i]);

	sort(nArr+1, nArr+n+1);
	dp[0] = 1;
	/*for (int i = 1; i <=n ; i++) {
		for (int j = m; j >= nArr[i]; j--) {
			for (int k = 1; k <= m; k++) {
				dp[j][k] += dp[j - nArr[i]][k - 1];
			}
		}
	}*/


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[j] += dp[j - nArr[i]];
		}
	}
	cout << dp[m];
}