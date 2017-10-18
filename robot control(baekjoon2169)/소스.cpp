#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;
#define MIN -987654321
#define max(a,b) ((a) > (b)?(a):(b))
long long dp[1011][1011][3];
int visit[1011][1011];
int dx[4] = { 1,-1,0 };
int dy[4] = { 0,0,1 };
int graph[1001][1001];
int n, m;
long long dfs(int y, int x, int d) {
	if (x == m && y == n)
		return dp[y][x][d] = graph[y][x];
	if (dp[y][x][d] != MIN) return dp[y][x][d];
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx <= m && ny > 0 && ny <= n && !visit[ny][nx]) {
			visit[ny][nx] = 1;
			dp[y][x][d] = max(dp[y][x][d], dfs(ny, nx, i) + graph[y][x]);
			visit[ny][nx] = 0;
		}
	}
	return dp[y][x][d];
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &graph[i][j]);
			//graph[i][j] = rand() % 100;
			dp[i][j][0] = MIN;
			dp[i][j][1] = MIN;
			dp[i][j][2] = MIN;
		}
	}
	for (int i = 1; i <= n; i++) dp[i][0][0] = MIN;
	if (n > 1001) {
		for (int i = n - 1; i >= 1; i -= 1) {
			if (i == 0) i = 1;
			dfs(i, 0, 0);
		}
	}
	else {
		dfs(1, 0, 0);
	}
	printf("%lld", dp[1][1][0]);
}