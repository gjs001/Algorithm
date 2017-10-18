#include <iostream>
using namespace std;


int dy[4] = {0,1,1,1};
int dx[4] = { 1,1,0,-1 };

char map[11][11];
int visit[11][11][4];
bool ans;



void dfs(int y, int x, int dir, int depth, int cnt) {
	if (depth == 5) {
		ans = true;
		return;
	}
	if (dir == -1) {
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10 || visit[ny][nx][i] || map[ny][nx] == 'O') continue;
			visit[ny][nx][i] = 1;
			if (map[ny][nx] == 'X') dfs(ny, nx, i, depth + 1, cnt);
			else if(cnt) {
				map[ny][nx] = 'X';
				dfs(ny, nx, i, depth + 1, 0);
				map[ny][nx] = '.';
			}
		}
	}
	else {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10 || visit[ny][nx][dir] || map[ny][nx] == 'O') return;
		visit[ny][nx][dir] = 1;
		if (map[ny][nx] == 'X') dfs(ny, nx, dir, depth + 1, cnt);
		else if (cnt) {
			map[ny][nx] = 'X';
			dfs(ny, nx, dir, depth + 1, 0);
			map[ny][nx] = '.';
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 10; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 'X') dfs(i, j, -1, 1, 1);
			else if (map[i][j] == '.') dfs(i, j, -1, 1, 0);
		}
	}
	if (ans) cout << "YES";
	else cout << "NO";
}