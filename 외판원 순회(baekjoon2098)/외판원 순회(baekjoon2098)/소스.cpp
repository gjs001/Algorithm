#include <iostream>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;
#define INF 987654321
#define min(a,b) ((a)>(b))?(b):(a)


typedef pair<int, int> P;
typedef pair<int, P> PP;
int map[17][17];
int n;
int dp[1 << 17][17];

int dfs(int now, int check, int start) {
	int &ret = dp[check][now];
	if (ret != -1) return ret;
	if (check == (1 << n) - 1) {
		return map[now][start]?map[now][start]:INF;
	}

	ret = INF;
	
	for (int i = 0; i < n; i++) {
		if (!( check & (1 << i)) && map[now][i]) {

			int bitv = check;
			bitv |= (1 << i);
			ret = min(ret,dfs(i, bitv, start) + map[now][i]);
	
		}

	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1, 0);

}