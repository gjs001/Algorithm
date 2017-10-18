#include <iostream>
using namespace std;

int h, w;
char map[10001][501];
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };
int ans = 0;
int flag = 0;

void dfs(int x, int y) {
	if (flag) return;
	if (x == w - 1) {
		ans++;
		flag = 1;
		return;
	}
	if (y < 0 || y >= h) return;
	if (map[y][x] == 'x') return;
	map[y][x] = 'x';
	dfs(x + 1, y - 1);
	dfs(x + 1, y);
	dfs(x + 1, y + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < h; i++) {
		flag = 0;
		dfs(0, i);
	}
	cout << ans;
}