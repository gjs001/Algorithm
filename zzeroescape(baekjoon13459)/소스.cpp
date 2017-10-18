#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

#define right 0
#define left 1
#define down 2
#define up 3
#define pii pair<int,int>
#define piii pair<int,pii>
#define piiii pair<int,piii>
int h, w;
int R, B;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char graph[101][101];

int coor(int y, int x, int k) {
	return y*k + x;
}
int toX(int A, int k) {
	return A % k;
}
int toY(int A, int k) {
	return A / k;
}

int rolling(int dir, int tar) {
	
	int cur = tar;
	int cx = toX(cur,w);
	int cy = toY(cur,w);
	int nx = cx;
	int ny = cy;
	int cnt = 0;

	while (nx >= 0 && nx < w && ny >= 0 && ny < h && graph[ny][nx] != '#') {
		nx += dx[dir];
		ny += dy[dir];
		cnt++;
		if (graph[ny][nx] == 'O') return h*w;
		

	}
	if(!cnt) return tar;
	else return coor(ny - dy[dir], nx - dx[dir], w);
}

int search() {
	queue<piiii> que;
	que.emplace(-1,make_pair(0, make_pair(R, B)));
	while (que.size()) {
		int depth = que.front().second.first;
		int cr = que.front().second.second.first;
		int cb = que.front().second.second.second;
		int prev = que.front().first;
		int crx = toX(cr, w);
		int cry = toY(cr, w);
		int cbx = toX(cb, w);
		int cby = toY(cb, w);
		que.pop();
		if (prev != -1) {
			if (prev < 2) prev = !prev;
			else if (prev == 2) prev = 3;
			else prev = 2;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr;
			int nb = cb;
			int nrx = crx + dx[i];
			int nry = cry + dy[i];
			int nbx = cbx + dx[i];
			int nby = cby + dy[i];
			if (nrx >= 0 && nrx < w && nry >= 0 && nry < h && graph[nry][nrx] != '#' && i != prev) {
				nr = rolling(i, cr);
			}
			if (nbx >= 0 && nbx < w && nby >= 0 && nby < h && graph[nby][nbx] != '#' && i != prev) {
				nb = rolling(i, cb);
			}
			if (cr != nr || cb != nb) {
				if (nb == nr && nb != w*h) {
					
					int tmp = nr;
					int tx = toX(tmp, w);
					int ty = toY(tmp, w);
					while (1) {
						if (nb == cb) {
							nr = coor(toY(nr, w) - dy[i], toX(nr, w) - dx[i], w);
							break;
						}
						if (nr == cr) {
							nb = coor(toY(nb, w) - dy[i], toX(nb, w) - dx[i], w);
							break;
						}
						tx -= dx[i];
						ty -= dy[i];
						tmp = coor(ty, tx, w);
						if (cr == tmp) { nb = coor(toY(nb, w) - dy[i], toX(nb, w) - dx[i], w); break; }
						if (cb == tmp) { nr = coor(toY(nr, w) - dy[i], toX(nr, w) - dx[i], w); break; }
					}
				}
				if (nr != w*h && nb != w*h && depth < 9 && (nr != cr || nb != cb)) {
					que.emplace(i, make_pair(depth + 1, make_pair(nr, nb)));
				}
				else if (nr == w*h && nb != w*h) {
					return 1;
				}
			}
		}
	}
	return 0;

}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		char tmp;
		scanf("%c", &tmp);
		for (int j = 0; j < w; j++) {
			scanf("%c", &graph[i][j]);
			if (graph[i][j] == 'R') R = coor(i, j, w);
			else if (graph[i][j] == 'B') B = coor(i, j, w);
		}
	}
	cout << search();
}