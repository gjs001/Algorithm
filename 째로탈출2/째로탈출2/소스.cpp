#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

#define red 0
#define blue 1
typedef pair<int, int> P;
typedef struct ball {
	int y;
	int x;
	bool color;
	int dir;
	int dist;
};

int w, h;
char map[11][11];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
P next_to[11][11][4];
ball red_start;
ball blue_start;
queue<ball> que;

bool dircheck(int pdir, int ndir){
	if (pdir == -1) return true;
	else if (pdir % 2 && ndir % 2) return false;
	else if (!(pdir % 2) && !(ndir % 2)) return false;
	else return true;
}

int Abs(int a) {
	if (a < 0) return (-a);
	return a;
}
int bfs() {
	int cnt = 0;
	while (que.size()) {
		int ans[4] = { 0,0,0,0 };
		ball cur_red[4];
		ball cur_blue[4];
		int blue_dist[4];
		int red_dist[4];
		memset(cur_red, 0, sizeof(cur_red));
		memset(cur_blue, 0, sizeof(cur_blue));
		memset(red_dist, 0, sizeof(red_dist));
		memset(blue_dist, 0, sizeof(blue_dist));
		while (cnt < 2) {
			ball now = que.front();
			que.pop();
			if (now.dist > 9) return -1;
			for (int i = 0; i < 4; i++) {
				if (!dircheck(now.dir, i)) continue;
				int ny = next_to[now.y][now.x][i].first;
				int nx = next_to[now.y][now.x][i].second;

				if (now.color == red) {
					if (map[ny][nx] == 'O') {
						ans[i] = now.dist +1;
					}
					
					red_dist[i] = Abs(ny - now.y) + Abs(nx - now.x);
					cur_red[i] = { ny,nx,red,i,now.dist+1 };
				}
				else {
					if (map[ny][nx] == 'O') {
						ans[i] = 0;
						red_dist[i] = 0;
						continue;
					}
					blue_dist[i] = Abs(ny - now.y) + Abs(nx - now.x);
					cur_blue[i] = { ny,nx,blue,i,now.dist+1 };
				}

			}
			cnt++;
		}
		cnt = 0;
		
		for (int i = 0; i < 4; i++) {
			if (ans[i]) return ans[i];
			if (red_dist[i] == 0 && blue_dist[i] == 0) continue;
			if (cur_red[i].y == cur_blue[i].y && cur_red[i].x == cur_blue[i].x) {
				if (blue_dist[i] > red_dist[i]) { cur_blue[i].y -= dy[i]; cur_blue[i].x -= dx[i]; }
				else { cur_red[i].x -= dx[i]; cur_red[i].y -= dy[i]; }

			}
			que.push(cur_red[i]);
			que.push(cur_blue[i]);
		}
		
			

	}
	return -1;
}


int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		char tmp;
		scanf("%1c", &tmp);
		for (int j = 0; j < w; j++) {
			scanf("%1c", &map[i][j]);
			if (map[i][j] == 'R') red_start = { i,j,red,-1,0 };
			if (map[i][j] == 'B') blue_start = { i,j,blue,-1,0 };
		}
	}
	que.push(red_start);
	que.push(blue_start);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '#' && map[i][j] == 'O') continue;
			for (int k = 0; k < 4; k++) {
				int ny = i;
				int nx = j;
				while (map[ny][nx] == '.' || map[ny][nx] == 'R' || map[ny][nx] == 'B') {
					ny += dy[k];
					nx += dx[k];
				}
				if (map[ny][nx] == 'O') next_to[i][j][k] = P(ny, nx);
				else next_to[i][j][k] = P(ny - dy[k], nx - dx[k]);

			}
		}
	}

	printf("%d",bfs());


}