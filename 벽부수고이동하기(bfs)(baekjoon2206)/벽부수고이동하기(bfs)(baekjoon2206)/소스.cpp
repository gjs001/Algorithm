#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;


char map[1001][1001];
int visit[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int w, h;

void bfs() {
	queue<PP> que;
	que.push(PP(1, P(0, 0)));
	visit[0][0][1] = 1;
	while (que.size()) {
		PP now = que.front();
		que.pop();
		int y = now.second.first;
		int x = now.second.second;
		int ct = now.first;
		if (y == h - 1 && x == w - 1) {
			printf("%d", visit[y][x][ct]);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i]; 
	
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] == '0' && (!visit[ny][nx][ct] || visit[ny][nx][ct] > visit[y][x][ct] + 1)) {
				visit[ny][nx][ct] = visit[y][x][ct] +1;
				que.push(PP(ct, P(ny, nx)));
			}
			else if (ct == 1 && map[ny][nx] == '1') {
				visit[ny][nx][0] = visit[y][x][ct]+1;
				que.push(PP(0, P(ny, nx)));
			}
		}

	}
	printf("%d", -1);
	return;
}
int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", &map[i]);
	}
	bfs();
}