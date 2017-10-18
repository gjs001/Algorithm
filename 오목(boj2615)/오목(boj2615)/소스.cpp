#include <iostream>

using namespace std;

int visit[20][20][4];
int map[20][20];

int ans;
int n = 19;

int dy[4] = {0,1,1,1};
int dx[4] = {1,1,0,-1};

bool omo(int y, int x) {
	int color = map[y][x];
	bool flag = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx <1 || ny > n || nx > n || map[ny][nx] != color || visit[ny][nx][i]) continue;
		visit[ny][nx][i] = 1;
		for (int j = 0; j < 19; j++) {
			ny += dy[i];
			nx += dx[i];
			if (ny < 1 || nx <1 || ny > n || nx > n || map[ny][nx] != color) break;
			visit[ny][nx][i] = 1;
			if (j == 2) flag = 1;
			if (j == 3) flag = 0;
		}
		if (flag) {
			if (i == 3) ans = 1;
			break;
		}
	}
	if (flag) return 1;
	else return 0;
}


int main() {
	ios::sync_with_stdio(false);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] && omo(i, j) && !flag) {
				if (ans) {
					i += 4 * dy[3];
					j += 4 * dx[3];
				}
				cout << map[i][j] << "\n" << i << " " << j << "\n";
				flag = 1;
				break;
			}

		}
	}
	if (!flag) cout << 0;
}