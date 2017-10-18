#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define INF 987654321
using namespace std;

int dp[1001][1001][2];
int visit[1001][1001];
char map[1001][1001];
int w, h;
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0, 0, 1, -1 };

int Min(int a, int b) {
	if (a > b) return b;
	return a;
}
int dfs(int y, int x, int t) {
	if (y == h- 1 && x == w - 1) {
		return 1;
	}
	int& ret = dp[y][x][t];
	if (ret != INF) return ret;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w || visit[ny][nx]) continue;
		if (map[ny][nx] == '0' ) {
			visit[ny][nx] = 1;
			ret = Min(ret, dfs(ny, nx, t) +1);
			visit[ny][nx] = 0;
		}
		else if (t == 1) {
			visit[ny][nx] = 1;
			ret = Min(ret, dfs(ny, nx, 0) +1);
			visit[ny][nx] = 0;
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; j < w; j++) {
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}
	visit[0][0];
	printf("%d",dfs(0, 0, 1));
}