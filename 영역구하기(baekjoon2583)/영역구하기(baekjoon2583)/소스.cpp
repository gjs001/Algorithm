#include <iostream>
#include <algorithm>

using namespace std;

int w, h;
int x_1[101], y_1[101], x_2[101], y_2[101];
int n;
int ans[1000];
int cnt;
int map[101][101];
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0,0,1,-1 };


int dfs(int y,int x) {
	
	
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] ) continue;
		map[ny][nx] = 1;
		ans += dfs(ny, nx);
	}
	return ans;
}

int main() {
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x_1[i], &y_1[i], &x_2[i], &y_2[i]);
	}
	for (int i = 0; i <n ; i++) {
		for (int j = y_1[i]; j < y_2[i]; j++) {
			for (int k = x_1[i]; k < x_2[i]; k++) {
				map[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j]) continue;
			map[i][j] = 1;
			ans[cnt++] = dfs(i, j);
		}
	}
	printf("%d\n", cnt);
	sort(ans, ans + cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", ans[i]);
	}
	
}