#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

int N;
int mem[501][501];
int dp[501][501];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &mem[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + mem[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + mem[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + mem[i][j];
			}
			if (i == N) {
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;

}