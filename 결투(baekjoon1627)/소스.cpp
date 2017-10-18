#include <iostream>
#include <cstring>
using namespace std;


int n;
int idx;
int s[3001];
int t[3001];
int q[3001];
int ans[3001];
int dp[3][3001];
char map[3001];
int clu[2];
/*
int ck(int n) {
	if (dp[n] != -1) return dp[n];
	else if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5) return dp[n] = 1;
	else if (n == 6) return dp[n] = 0;
	else {
		for (int i = 3; i <= 5; i++) {
			if (ck(n-i) == 0) return dp[n] = 1;
		}
		for (int i = 1; i <= (n - 5)/2; i++) {
			if (ck(i) && ck((n - 5) - i) || (ck(i) == 0 && ck((n-5)-i) == 0)) {
				return dp[n] = 1;
			}
		}
	}
	return dp[n] = 0;
}*/


int main() {

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		if (map[i] == 'P') {
			s[i] = 1;
			q[i] = 1;
			for (int j = -2; j < 3; j++) {
				if (j == 0) continue;
				if (i + j >= 0 && i + j < n && map[i + j] != 'P')q[i + j]++;
			}
			t[i] = -1;
		}
		else {
			int j = 1;
			while (i - j >= 0 && map[i - j] == 'P') {
				t[i]++;
				j++;
			}
			j = 1;
			while (i + j < n && map[i + j] == 'P') {
				t[i]++;
				j++;
			}
		}




	}
	for (int i = 0; i < n; i++) {
		if (t[i] >= 2) ans[idx++] = i + 1;
	}
	if (!idx) {
		for (int i = 0; i < n; i++) {
			memset(clu, 0, sizeof(clu));

			if (q[i] == 0) {
				int sav[5];
				int cnt = 0;
				for (int j = -2; j < 3; j++) {
					if (i + j >= 0 && i + j < n && q[i + j] == 0) {
						sav[cnt++] = i + j;
						q[i + j] = 1;
					}
				}

				int len = 0;
				int ss = 0;
				for (int j = 0; j < n; j++) {
					if (q[j] == 0) {
						len++;
					}
					else if (len) {
						
						
						if (len == 1 || len == 2 || len == 3) {
							clu[0] += 1;

						}
						else if (len == 6) {
							clu[0] += 2;
						}
						else if(len >0) {
							clu[1] += 1;
						}
						len = 0;
					}

					if (j == n - 1 && q[j] == 0) {
						
						if (len == 1 || len == 2 || len == 3) {
							clu[0] += 1;

						}
						else if (len == 6) {
							clu[0] += 2;
						}
						else if(len > 0){
							clu[1] += 1;
						}
						len = 0;
					}

				}
				if (!(clu[1] % 2) && !(clu[0] % 2)) ans[idx++] = i + 1;
				for (int j = 0; j < cnt; j++) {
					q[sav[j]] = 0;
				}
			}
		}
	}
	if (!idx) cout << "LOSING\n";
	else if (idx) {
		cout << "WINNING\n";
		for (int i = 0; i < idx; i++) {
			cout << ans[i];
			if (i != idx - 1) cout << " ";
		}
	}
}