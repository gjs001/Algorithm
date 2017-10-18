#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int w, h;
int map[21][21];
int com[1001];
int sx, sy, k;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

class dice {
public:
	int shape[6];
	int value[6];
	int t;
	int b;
	dice() {
		for (int i = 0; i < 6; i++) {
			shape[i] = i;
			value[i] = 0;
		}
		t = 0;
		b = 5;
	}
	void move(int dir) {
		if (dir == 2) {
			int ts;
			ts = shape[0];
			shape[0] = shape[4];
			shape[4] = shape[5];
			shape[5] = shape[1];
			shape[1] = ts;
			t = shape[0];
			b = shape[5];
		}
		else if (dir == 3) {
			int ts;
			ts = shape[0];
			shape[0] = shape[1];
			shape[1] = shape[5];
			shape[5] = shape[4];
			shape[4] = ts;
	
			t = shape[0];
			b = shape[5];
		}
		else if(dir == 0) {
			int ts;
			ts = shape[0];
		
			shape[0] = shape[3];
			shape[3] = shape[5];
			shape[5] = shape[2];
			shape[2] = ts;
		
			t = shape[0];
			b = shape[5];
		}
		else if (dir == 1){
			int ts;
			ts = shape[0];

			shape[0] = shape[2];
			shape[2] = shape[5];
			shape[5] = shape[3];
			shape[3] = ts;
		
			t = shape[0];
			b = shape[5];
		}
	}
	void touch(int y,int x) {
		if (!map[y][x]) { map[y][x] = value[this->b]; 
		}
		else {
			value[this->b] = map[y][x];
			map[y][x] = 0;
		}
	}
};



int main() {
	cin >> h >> w >> sy >> sx >> k;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		com[i] = tmp - 1;
	}
	int cnt = 0;
	int y = sy;
	int x = sx;
	dice a;
	while (cnt < k) {
		a.touch(y, x);
		int nd = com[cnt];
		while (y + dy[nd] < 0 || y + dy[nd] >= h || x + dx[nd] < 0 || x + dx[nd] >= w) {
			nd = com[++cnt];
			if (cnt == k) return 0;
		}
		a.move(nd);
		printf("%d\n", a.value[a.t]);

		y += dy[nd];
		x += dx[nd];
		cnt++;

		
	}
}
