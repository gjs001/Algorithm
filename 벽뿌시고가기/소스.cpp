#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int visit[1001][1001][2];
int dp[1001][1001][2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
char map[1001][1001];
int w, h;

int dfs(int y, int x, int cnt) {
	if (y == h - 1 && x == w - 1) {
		return 1;
	}
	int &ret = dp[y][x][cnt];
	if (ret != INF) return ret;
	for (int i = 0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx <0 || ny >= h || nx >= w) continue;
		if (cnt == 0 && map[ny][nx] == '1' && !visit[ny][nx][0]) {
			visit[ny][nx][1] = 1;
			ret = min(ret, dfs(ny, nx, 1) + 1);
			visit[ny][nx][1] = 0;
		}
		if (map[ny][nx] == '0' && !visit[ny][nx][cnt]) {
			visit[ny][nx][cnt] = 1;
			ret = min(ret, dfs(ny, nx, cnt) + 1);
			visit[ny][nx][cnt] = 0;
		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {

			cin >> map[i][j];
			dp[i][j][0] = INF;
			dp[i][j][1] = INF;
		}
	}
	visit[0][0][0] = 1;
	int ans = dfs(0, 0, 0);
	if (ans >= INF) cout << -1;
	else cout << ans;
}