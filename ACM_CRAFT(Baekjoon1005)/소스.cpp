#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>


using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

queue<int> que;
bool map[1001][1001];
int dp[1001];
int contime[1001];
int cntarr[1001];
int T, N, K;
int last;

void search() {

	for (int i = 1; i <= N; i++) {
		if (cntarr[i] == 0) {
			dp[i] = contime[i];
			que.push(i);
			cntarr[i]--;
		}
	}
	while (que.size()) {
		int cur = que.front();
		que.pop();
		for (int i = 1; i <= N; i++) {
			if (map[cur][i]) {
				dp[i] = max(dp[i], dp[cur] + contime[i]);
				cntarr[i]--;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (cntarr[i] == 0) {
				que.push(i);
				cntarr[i]--;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = false;
		}
	}
}

int main() {
	cin >> T;

	while (T--) {
		scanf("%d %d", &N,&K);
		for (int i = 1; i <= N; i++) dp[i] = 0;
		for (int i = 1; i <= N; i++) cntarr[i] = 0;
		for (int i = 1; i <= N; i++) scanf("%d", &contime[i]);
		for (int i = 0; i < K; i++) {
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			map[tmp1][tmp2] = true;
			cntarr[tmp2]++;
		}
		scanf("%d", &last);

		search();
		printf("%d\n", dp[last]);

	}
}


