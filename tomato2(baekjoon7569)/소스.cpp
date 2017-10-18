#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;

typedef struct tot {
	int x =0;
	int y =0;
	int z =0;
	tot() {};
	tot(int a, int b, int c) { z = a; y = b; x = c; }
}tot;


int n, m, h;
int map[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int visit[101][101][101];
int znum;

int bfs() {

	queue<tot> q1;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 1) {
					tot tmp(i, j, k);
					q1.push(tmp);
				}
			}
		}
	}


	while (q1.size()) {
		queue<tot> q2;
		while (q1.size()) {
			tot c = q1.front();
			q1.pop();
			for (int i = 0; i < 6; i++) {
				int nz = c.z + dz[i];
				int ny = c.y + dy[i];
				int nx = c.x + dx[i];
				if (nx < m && nx >= 0 && ny < n && ny >= 0 && nz < h && nz >= 0 && !visit[nz][ny][nx] && map[nz][ny][nx] == 0) {
					visit[nz][ny][nx] = 1;
					cnt++;
					map[nz][ny][nx] = 1;
					tot tmp(nz, ny, nx);
					q2.push(tmp);
				}
			}
		}
		while (q2.size()) {
			q1.push(q2.front());
			q2.pop();
		}
		ans++;
	}
	if (znum == cnt) return ans-1;
	else return -1;
}

int main() {

	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 0) znum++;
			}
		}
	}

	printf("%d", bfs());
}