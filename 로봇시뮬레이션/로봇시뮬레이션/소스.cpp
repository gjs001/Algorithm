#include <iostream>
	
using namespace std;

typedef struct robot {
	int x;
	int y;
	int dir;
};

int w, h;
int n, m;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int map[102][102];
robot arr[101];

int get_dir(char cmd) {
	if (cmd == 'N') {
		return 0;
	}
	if (cmd == 'W') {
		return 1;
	}
	if (cmd == 'S') {
		return 2;
	}
	if (cmd == 'E') {
		return 3;
	}
}
int change_dir(char cmd, int n_dir, int cnt) {
	if (cmd == 'L') {
		return (n_dir + cnt) % 4;
	}
	if (cmd == 'R') {
		int tmp = n_dir - (cnt % 4);
		return (4 + tmp)%4;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int ans = 0;
	cin >> w >> h;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		arr[i].x = x;
		arr[i].y = h + 1 - y;
		arr[i].dir = get_dir(d);
		map[h + 1 - y][x] = i;
	}
	while (m--) {
		int num, cnt;
		char cmd;
		cin >> num >> cmd >> cnt;
		if (cmd != 'F') {
			arr[num].dir = change_dir(cmd, arr[num].dir, cnt);
		}
		else {
			int ny = arr[num].y;
			int nx = arr[num].x;
			for (int i = 0; i < cnt; i++) {
				ny += dy[arr[num].dir];
				nx += dx[arr[num].dir];
				if (ny <= 0 || nx <= 0 || ny > h || nx > w) {
					cout << "Robot " << num << " crashes into the wall";
					return 1;
				}
				if (map[ny][nx]) {
					cout << "Robot " << num << " crashes into robot "<< map[ny][nx];
					return 1;
				}
			}
			map[arr[num].y][arr[num].x] = 0;
			arr[num].y = ny;
			arr[num].x = nx;
			map[ny][nx] = num;
		}
	}
	cout << "OK";
}