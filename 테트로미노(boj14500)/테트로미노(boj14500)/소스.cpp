#include <iostream>

using namespace std;
int map[503][503];
int dp[2][503][503];

int main() {
	int w, h;
	int ans = 0;
	std::ios::sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			dp[0][i][j] = map[i][j] + map[i][j + 1];
		}
	}
	for (int i = 0; i < h-1; i++) {
		for (int j = 0; j < w; j++) {
			dp[1][i][j] = map[i][j] + map[i + 1][j];
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (j + 3 < w) { // ㅡ형
				if (ans < dp[0][i][j] + dp[0][i][j + 2]) ans = dp[0][i][j] + dp[0][i][j + 2];
			}
			if (i + 3 < h) { // ㅣ형
				if (ans < dp[1][i][j] + dp[1][i + 2][j]) ans = dp[1][i][j] + dp[1][i + 2][j];
			}
			if (i + 1 < h && j +1 < w) { // ㅁ형
				if (ans < dp[0][i][j] + dp[0][i + 1][j]) ans = dp[0][i][j] + dp[0][i + 1][j];
			}
			if (j - 1 >= 0 && i + 1 < h && j + 1 < w) { // ㄴ형 
				int tmp = dp[0][i][j] + dp[1][i][j - 1];
				if (ans < tmp) ans = tmp;
			}
			if (i - 2 >= 0 && j +1 < w) {
				int tmp = dp[0][i][j] + dp[1][i - 2][j];
				if (ans < tmp) ans = tmp;
			}
			if (i - 1 >= 0 && j + 2 < w) {
				int tmp = dp[0][i][j] + dp[1][i - 1][j + 2];
				if (ans < tmp) ans = tmp;
			}
			if (i + 2 < h && j+1 < w) {
				int tmp = dp[0][i][j] + dp[1][i + 1][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (i - 1 >= 0 && j + 2 < w) { // -_ 형
				int tmp = dp[0][i][j] + dp[0][i - 1][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (i + 1 < h && j + 2 < w) {
				int tmp = dp[0][i][j] + dp[0][i + 1][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (i + 2 < h && j + 1 < w) {
				int tmp = dp[1][i][j] + dp[1][i + 1][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (i - 1 >= 0 && j + 1 < w && i +1 < h) {
				int tmp = dp[1][i][j] + dp[1][i - 1][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (j - 1 >= 0 && j + 1 < w && i + 1 < h) { // ㅗ형
				int tmp = dp[0][i][j - 1] + dp[0][i][j] + dp[1][i][j] - 2 * map[i][j];
				if (ans < tmp) ans = tmp;
			}
			if (j - 1 >= 0 && i - 1 >= 0 && i + 1 < h) {
				int tmp = dp[0][i][j - 1] + dp[1][i - 1][j] + dp[1][i][j] - 2 * map[i][j];
				if (ans < tmp) ans = tmp;
			}
			if (j + 1 < w && i - 1 >= 0 && i + 1 < h) {
				int tmp = dp[0][i][j] + dp[1][i - 1][j] + dp[1][i][j] - 2 * map[i][j];
				if (ans < tmp) ans = tmp;
			}
			if (j - 1 >= 0 && j + 1 < w && i - 1 >= 0) {
				int tmp = dp[0][i][j-1] + dp[0][i][j] + dp[1][i-1][j] - 2 * map[i][j];
				if (ans < tmp) ans = tmp;
			}
			if (j - 1 >= 0 && i - 1 >= 0 && j +1 <w) { // ㄱ형 
				int tmp = dp[0][i][j] + dp[1][i-1][j - 1];
				if (ans < tmp) ans = tmp;
			}
			if (i - 2 >= 0 && j +1 < w) {
				int tmp = dp[0][i][j] + dp[1][i - 2][j + 1];
				if (ans < tmp) ans = tmp;
			}
			if (i + 1 < h && j + 2 < w) {
				int tmp = dp[0][i][j] + dp[1][i][j + 2];
				if (ans < tmp) ans = tmp;
			}
			if (i + 2 < h && j +1 < w) {
				int tmp = dp[0][i][j] + dp[1][i + 1][j];
				if (ans < tmp) ans = tmp;
			}

		}
	}
	cout << ans;
}