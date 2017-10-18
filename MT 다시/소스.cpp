#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int visit[1001];
int finished[1001];
int edge[1001];
int ans[1001];
int ncmp[1001];
int ccmp[1001];
int dp[1001][1001];
int n, K;
int res, acnt, ccnt = 1;
P compo[1001];
int dfs(int now) {
	int cnt = 0;
	visit[now] = 1;
	int next = edge[now];
	if (visit[next] == 1) {
		if (!finished[next]) {
			for (int i = next; i != now; i = edge[i]) {
				ncmp[i] = ccnt;
				cnt++;
			}
			cnt++;
			ncmp[now] = ccnt;
			compo[ccnt].first = compo[ccnt].second = cnt;
			ccnt++;
		}
		else {
			ncmp[now] = ncmp[next];

		}
	}
	else {
		cnt = dfs(next);
		if (!ncmp[now])ncmp[now] = ncmp[next];
	}

	finished[now] = 1;
	return cnt;
}



int main() {
	ios::sync_with_stdio(false);
	
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> edge[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		ccmp[ncmp[i]]++;
	}
	for (int i = 1; i<ccnt; i++) {
		compo[i].second = ccmp[i];
	}
	for (int i = 0; i <= K; i++) {
		for (int j = 1; j<ccnt; j++) {
			for (int k = compo[j].first; k <= compo[j].second ; k++) {
				if (i - k >= 0) {
					dp[i][j] = max(dp[i][j],max(dp[i][j - 1], dp[i - k][j - 1] + k));
				}
				else {
					dp[i][j] = max(dp[i][j - 1],dp[i][j]);
				}
			}
		}
	}


	cout << dp[K][ccnt - 1];
}