#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;


int n;

int dp[1001];
int narr[1001];
int ans = 0;

int dfs(int now) {
	int &res = dp[now];
	if (now == n) {
		return 0;
	}
	if (res != -1) return res;
	res = 0;
	for (int i = now + 1; i <= n;i++) {
		if(narr[now] < narr[i])	res = max(res, dfs(i)+1);
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
	}
	memset(dp, -1, sizeof(dp));
	narr[n] = 987654321;
	for (int i = 0; i < n; i++) {
		ans = max(ans,dfs(i));
	}
	cout << ans;
}