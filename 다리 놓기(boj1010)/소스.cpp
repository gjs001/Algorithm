#include <iostream>
#include <cstring>

using namespace std;

int t,n, m;
long long dp[31][31];
long long dfs(int w, int e) {
	long long &ret = dp[w][e];
	if (w == n) {
		return 1;
	}
	if (ret != -1) return ret;
	ret = 0;
	for (int i = e + 1; i <= m -(n-w)+1; i++) {
		ret += dfs(w + 1, i);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		cout << dfs(0, 0) << "\n";
	}
}