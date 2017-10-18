#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> P;
P narr[513];
int t, n;
double dp[513][513];

double get_dist(P prev, P now) {
	int y = now.first - prev.first;
	int x = now.second - prev.second;
	return sqrt((y*y + x*x));
}

double dfs(int up, int down) {
	double &ret = dp[up][down];
	if (ret) {
		return ret;
	}
	if (down == n) {
		return get_dist(narr[up], narr[down]);
	}
	ret = min(dfs(up, down + 1) + get_dist(narr[down], narr[down + 1]), dfs(down, down + 1) + get_dist(narr[up], narr[down + 1]));
	return ret;
}

int main() {

	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &narr[i].first, &narr[i].second);
		}
		printf("%lf\n", dfs(1, 1));
	}
}