#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define limit 100000000000000000
using namespace std;

int n;
int map[101][101];
int visit[101][101];
long long dp[101][101];
long long dpl[101][101];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
long long dfs(int x, int y, int depth, int prev) {
	if (x == n - 1 && y == n - 1 ) {
		if (depth) return 0;
 		else return 1;
	}
	if (dp[y][x] && !depth) return dp[y][x];
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < n && nx >= 0 && ny < n && ny >= 0 && !visit[ny][nx] && (i == prev || !depth)) {
			visit[ny][nx] = 1;
			if (depth) {
				visit[ny][nx] = 0;
				return dfs(nx, ny, depth - 1, i);
			}
			else dp[y][x] += dfs(nx, ny, map[y][x]-1, i);

			visit[ny][nx] = 0;
	
		}
	}
	if(!depth)	return dp[y][x];
	else return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%lld", dfs(0, 0, 0, -1));
}