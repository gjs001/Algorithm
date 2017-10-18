#include <stdio.h>

int w, h;
int visit[26][26];
char map[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans[3];

int direction(char tmp) {
	if (map[ny][nx] == 124 || map[ny][nx] == '-' || map[ny][nx] == '+') {
		dir = p;
	}
	else if (map[ny][nx] == '1') {
		int tmp = dir;
		if (p == 1) dir = 2;
		else dir == 0;
		p = tmp;
	}
	else if (map[ny][nx] == '2') {
		int tmp = dir;
		if (p == 2) dir == 0;
		else dir == 3;
		p = tmp;
	}
	else if (map[ny][nx] == '3') {
		int tmp = dir;
		if (p == 2) dir == 1;
		else dir == 3;
		p = tmp;
	}
	else if (map[ny][nx] == '4') {
		int tmp = dir;
		if (p == 0) dir == 2;
		else dir == 1;
		p = tmp;
	}
}

bool dfs(int y, int x, int prev) {
	int dir = 0;

	int ny = y;
	int nx = x;
	int p = prev;
	while (ny >= 0 && nx >= 0 && ny < h && nx <w) {
		
	if (map[ny][nx] == '.') {
			for (int i = 0; i < 7; i++) {

				if (dfs(ny+dy[i], nx+dx[i], i)) {

				}
			}
		}
		else if (map[ny][nx] == 'Z') {
			return 1;
		}
		ny += dy[dir];
		nx += dx[dir];
	}
	
	return 0;
}


