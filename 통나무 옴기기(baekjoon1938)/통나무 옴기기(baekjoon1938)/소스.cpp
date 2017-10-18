#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;
struct tong {
	P one;
	P two;
	P thr;
	int dir;
	int d;
};

bool equal(tong a, tong b) {
	if (a.one == b.one && a.thr == b.thr && a.two == b.two && a.dir == b.dir) return 1;
	else return 0;
}

int n;
char map[51][51];
bool visit[50][50][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int rx[2] = { 1,-1 };
int ry[2] = { -1,1 };
int main() {
	cin >> n;
	int init = 1;
	int init2 = 1;
	tong s, e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (init && map[i][j] == 'B') {
				if (map[i + 1][j] == 'B') s = tong{ P(i,j),P(i + 1,j),P(i + 2,j), 1,0 };
				else s = tong{ P(i,j),P(i,j + 1),P(i,j + 2), 0,0 };
				init = 0;
			}
			if (init2 && map[i][j] == 'E') {
				if (map[i + 1][j] == 'E') e = tong{ P(i,j),P(i + 1,j),P(i + 2,j), 1,0 };
				else e = tong{ P(i,j),P(i,j + 1),P(i,j + 2), 0,0 };
				init2 = 0;
			}
		}
	}


	queue<tong> que;
	que.push(s);
	visit[s.two.first][s.two.second][s.dir] = 1;
	while (que.size()) {
		tong now = que.front();
		que.pop();
		if (equal(now, e)) {
			cout << now.d; 
			return 0;
		}


		for (int i = 0; i < 4; i++) {
			int oy = now.one.first + dy[i];
			int ox = now.one.second + dx[i];
			int ty = now.two.first + dy[i];
			int tx = now.two.second + dx[i];
			int thy = now.thr.first + dy[i];
			int thx = now.thr.second + dx[i];
			if (oy < 0 || ox < 0 || oy >= n || ox >= n || map[oy][ox] == '1') continue;
			if (ty < 0 || tx < 0 || ty >= n || tx >= n || map[ty][tx] == '1') continue;
			if (thy < 0 || thx < 0 || thy >= n || thx >= n || map[thy][thx] == '1') continue;
			if (visit[ty][tx][now.dir]) continue;
			visit[ty][tx][now.dir] = 1;
			que.push(tong{ P(oy, ox), P(ty, tx), P(thy, thx), now.dir, now.d + 1 });

		}
		for (int i = 0; i < 1; i++) {
			int flag = 0;
			int nd = now.dir;
			int oy = now.one.first + ry[nd];
			int ox = now.one.second + rx[nd];
			int ty = now.two.first;
			int tx = now.two.second;
			int thy = now.thr.first + rx[nd];
			int thx = now.thr.second + ry[nd];
			if (oy < 0 || ox < 0 || oy >= n || ox >= n || map[oy][ox] == '1') continue;
			if (ty < 0 || tx < 0 || ty >= n || tx >= n || map[ty][tx] == '1') continue;
			if (thy < 0 || thx < 0 || thy >= n || thx >= n || map[thy][thx] == '1') continue;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (map[ty + ry[i]][tx + rx[j]] == '1') flag = 1;
				}
			}
			if (flag) continue;
			if (visit[ty][tx][!now.dir]) continue;
			visit[ty][tx][!now.dir] = 1;
			que.push(tong{ P(oy, ox), P(ty, tx), P(thy, thx), !now.dir, now.d + 1 });
		}
	}
	cout << 0;
	return 0;

}