#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define INF 987654321
int T, n;
int chap[501];
int dp[501][501];
int sum[501];



int main() {

	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) scanf("%d", &chap[i]);
		
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + chap[i];

		for (int i = 1; i < n; i++) {
			for (int j = 1; j + i <= n; j++) {

				dp[j][j+i] = INF;
				for (int k = j; k < j+i; k++) {
					dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k + 1][j+i] + sum[j+i] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][n] << endl;
	}
}