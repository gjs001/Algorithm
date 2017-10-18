#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

map<int, P> m;
int w, h;
int y, x;
int k;
int dir;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visit[1001][1001];
int main() {
	scanf("%d %d", &w, &h);
	scanf("%d", &k);

	for (int i = 1; i <= w*h; i++) {
		m[i] = P(y, x);
		visit[y][x] = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= h || nx >= w || ny < 0 || nx < 0 || visit[ny][nx]) {
			dir += 1;
			if (dir == 4) dir = 0;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		y = ny;
		x = nx;
		


	}
	if (k <= w*h) printf("%d %d",m[k].second+1, m[k].first + 1);
	else printf("0");

}
