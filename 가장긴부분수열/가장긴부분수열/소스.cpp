#include <iostream>
#include <algorithm>
int dp[1002];
int narr[1001];

using namespace std;
int n;
int dfs(int now) {
	int &ret = dp[now];
	if (now == n + 1) {
		return 0;
	}
	if (ret) return ret;

	for (int i = now; i <= n+1; i++) {
		if (narr[now] < narr[i]) ret = max(ret, dfs(i) + 1);
	}
	return ret;
}


int main() {

	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> narr[i];
	}
	narr[n + 1] = 1001;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = dfs(i);
		if (ans < tmp) ans = tmp;
	}
	cout << ans;
}
