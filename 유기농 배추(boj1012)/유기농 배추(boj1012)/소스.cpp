#include <iostream>
#include <cstring>
using namespace std;

int w, h, k;
int snum;
int map[51][51];
int visit[51][51];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
void dfs(int y,int x) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= h || nx >= w || ny < 0 || nx < 0 || visit[ny][nx] || !map[ny][nx]) continue;
		visit[ny][nx] = snum;
		dfs(ny, nx);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		snum = 0;
		cin >> w >> h >> k;
		for (int i = 0; i < k; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			map[t2][t1] = 1;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visit[i][j]) {
					snum++;
					dfs(i, j);
				}
			}
		}
		cout << snum << "\n";
	}
}