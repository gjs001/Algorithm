#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

char t1[1002];
char t2[1002];
int dp[1002][1002];
int n, m, cnt;
char ans[1002];
char tmp[1002];
int main() {
	scanf("%s", &t1[1]);
	scanf("%s", &t2[1]);

	n = strlen(t1 + 1);
	m = strlen(t2 + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t1[i] == t2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int cury = n;
	int curx = m;
	while (curx > 0 && cury > 0) {
		int now = dp[cury][curx];
		int left = dp[cury][curx - 1];
		int up = dp[cury - 1][curx];
		if (now > left && now > up) {
			ans[cnt++] = t1[cury];
			curx = curx - 1;
			cury = cury - 1;
		}
		else if (left > up) {
			curx = curx - 1;
		}
		else {
			cury = cury - 1;
		}
	}
	for (int i = 0; i < cnt; i++) {
		tmp[i] = ans[cnt - i -1];
	}
	cout << dp[n][m] << endl << tmp;

}