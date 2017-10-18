#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 2000000000000000000
int t, n, start;
long long map[100][100];
long long dp[101][101][2];
long long add[101][101][2];
int main() {
	cin >> t;
	while (t--) {

		cin >> n >> start;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n -1; i++) {
			int tmp;
			cin >> tmp;
			
			for (int j = 0; j < i+1; j++) {
				for (int k = i + 1; k < n; k++) {
					map[j][k] += tmp;
					map[k][j] += tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < 2; k++) {
			dp[i][j][k] = INF; add[i][j][k] = INF;
		}

		dp[0][0][0] = dp[0][0][1] = 0;
		add[0][0][0] = add[0][0][1] = 0;
		for (int i = 1; i < start; i++) {
			dp[i][0][0] = dp[i - 1][0][0] + add[i-1][0][0] + map[start - 1 -(i - 1)][start - 1 - i];
			add[i][0][0] = add[i - 1][0][0] + map[start - 1 - (i - 1)][start - 1 - i];
		}
		for (int i = 1; i <= n - start ; i++) {
			dp[0][i][1] = dp[0][i-1][1] + add[0][i - 1][1] + map[start- 1 + i - 1][start -1 + i];
			add[0][i][1] = add[0][i - 1][1] + map[start - 1 + i - 1][start - 1 + i];
		}

		for (int i = 1; i < start; i++) {
			for (int j = 1; j <= n - start; j++) {
				if (dp[i - 1][j][1] + add[i - 1][j][1] + map[start - 1 + j][start - 1 - i] >dp[i - 1][j][0] + add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i]) {
					dp[i][j][0] = dp[i - 1][j][0] + add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i];
					add[i][j][0] = add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i];
				}
				else if (dp[i - 1][j][1] + add[i - 1][j][1] + map[start - 1 + j][start - 1 - i] < dp[i - 1][j][0] + add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i]) {
					dp[i][j][0] = dp[i - 1][j][1] + add[i - 1][j][1] + map[start - 1 + j][start - 1 - i];
					add[i][j][0] = add[i - 1][j][1] + map[start - 1 + j][start - 1 - i];
				}
				else {
					if (add[i - 1][j][1] + map[start - 1 + j][start - 1 - i] > add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i]) {
						dp[i][j][0] = dp[i - 1][j][0] + add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i];
						add[i][j][0] = add[i - 1][j][0] + map[start - 1 - (i - 1)][start - 1 - i];
					}
					else {
						dp[i][j][0] = dp[i - 1][j][1] + add[i - 1][j][1] + map[start - 1 + j][start - 1 - i];
						add[i][j][0] = add[i - 1][j][1] + map[start - 1 + j][start - 1 - i];
					}
				}
				if (dp[i][j - 1][1] + add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j] > dp[i][j - 1][0] + add[i][j - 1][0] + map[start - 1 - i][start - 1 + j]) {
					dp[i][j][1] = dp[i][j - 1][0] + add[i][j - 1][0] + map[start - 1 - i][start - 1 + j];
					add[i][j][1] = add[i][j - 1][0] + map[start - 1 - i][start - 1 + j];
				}
				else if (dp[i][j - 1][1] + add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j] < dp[i][j - 1][0] + add[i][j - 1][0] + map[start - 1 - i][start - 1 + j]) {
					dp[i][j][1] = dp[i][j - 1][1] + add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j];
					add[i][j][1] = add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j];
				}
				else {
					if (add[i][j - 1][0] + map[start - 1 - i][start - 1 + j] > add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j]) {
						dp[i][j][1] = dp[i][j - 1][1] + add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j];
						add[i][j][1] = add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j];
					}
					else {
						dp[i][j][1] = dp[i][j - 1][0] + add[i][j - 1][0] + map[start - 1 - i][start - 1 + j];
						add[i][j][1] = add[i][j - 1][0] + map[start - 1 - i][start - 1 + j];
					}
				}
				//dp[i][j][1] = min(dp[i][j - 1][1] + add[i][j-1][1] + map[start - 1 + j - 1][start - 1 + j], dp[i][j - 1][0] + add[i][j-1][0] + map[start - 1 - i][start - 1 + j]);
				//add[i][j][1] = min(add[i][j - 1][1] + map[start - 1 + j - 1][start - 1 + j], add[i][j - 1][0] + map[start - 1 - i][start - 1 + j]);
			}
		}
		
		long long ans = min(dp[start - 1][n - start][1], dp[start - 1][n - start][0]);
		printf("%lld\n", ans);
	}
}