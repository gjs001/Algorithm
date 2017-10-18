#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321
#define min(a,b) ((a)<(b))?(a):(b)
int w, h;
int map[9][9];
int visit[9][9];
int virus[11];
int cnt;
int rs;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int wv[64][64][64];

int bfs() {
	int res = 0;
	queue<int> que;
	for (int i = 0; i < cnt; i++) {
		que.push(virus[i]);
		visit[virus[i] / w][virus[i] % w] = 1;
	}
	while (que.size()) {
		int now = que.front();
		que.pop();
		int y = now / w;
		int x = now % w;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] != 0 || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			que.push(ny*w + nx);
			res++;
		}
	}
	return res;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virus[cnt++] = i*w + j;
			if (map[i][j] == 0) rs++;
		}
	}
	int vr = INF;
	for (int i = 0; i < w*h; i++) {
		if (map[i / w][i%w] != 0) continue;
		map[i / w][i%w] = 4;
		for (int j = 0; j < w*h; j++) {
			if (map[j / w][j%w] != 0)continue;
			map[j / w][j%w] = 4;
			for (int k = 0; k < w*h; k++) {
				if (map[k / w][k%w] != 0)continue;
				if (wv[i][j][k]) continue;
				wv[i][j][k] = wv[i][k][j] = wv[j][i][k] = wv[j][k][i] = wv[k][i][j] = wv[k][j][i] = 1;
				map[k / w][k%w] = 4;
				memset(visit, 0, sizeof(visit));
				int res = bfs();
				vr = min(vr, res);
				map[k/ w][k%w] = 0;
			}
			map[j / w][j%w] = 0;
		}
		map[i / w][i%w] = 0;
	}

	int ans = rs - vr - 3;
	printf("%d", ans);
}