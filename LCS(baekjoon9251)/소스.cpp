#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

char t1[1002];
char t2[1002];
int dp[1002][1002];
int n, m;
int main() {
	scanf("%s", &t1[1]);
	scanf("%s", &t2[1]);

	n = strlen(t1 + 1);
	m = strlen(t2 + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t1[i] == t2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][m];
}