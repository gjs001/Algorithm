#include <cstdio>
#include <cstring>

long long dp[31][31];
int n, t;

long long dfs(int w, int h) {
	long long &ret = dp[w][h];
	if (ret) return ret;
	if (w == 0) return 1;
	ret += dfs(w - 1, h + 1);
	if (h) ret += dfs(w, h - 1);
	return ret;
}

int main() {

	while (1) {
		scanf("%d", &n);
		if (!n) return 1;
		memset(dp, 0, sizeof(dp));
		printf("%lld\n", dfs(n, 0));
	}

}