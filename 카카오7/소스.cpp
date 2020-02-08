#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int my, mx;
enum mode {
	garo,
	sero
};

bool checkOutingMap(int y, int x) {
	if (y > 0 && y <= my && x > 0 && x <= mx) return true;
	return false;
}

struct drone {
	int y1, x1;
	int y2, x2;
	int mode;
	int cnt;
	drone() { y1 = 1; x1 = 1; y2 = 1; x2 = 2; mode = garo; cnt = 0; }
	bool can_cw(int y, int x) {
		if (mode == garo) {
			if (y == y1 && x == x1) {
				if (checkOutingMap(y2 + 1, x2 - 1) && map[y2 + 1][x2] == 0 && map[y2 + 1][x2 - 1] == 0) return true;
				return false;
			}
			else {
				if (checkOutingMap(y1 - 1, x1 + 1) && map[y1 - 1][x1] == 0 && map[y1 - 1][x1 + 1] == 0) return true;
				return false;
			}
		}
		else {
			if (y == y1 && x == x1) {
				if (checkOutingMap(y2 - 1, x2 - 1) && map[y2][x2 - 1] == 0 && map[y2 - 1][x2 - 1] == 0) return true;
				return false;
			}
			else {
				if (checkOutingMap(y1 + 1, x1 + 1) && map[y1][x1 + 1 ] == 0 && map[y1 + 1][x1 + 1] == 0) return true;
				return false;
			}
		}
	}
	bool can_ccw(int y, int x) {
		if (mode == garo) {
			if (y == y1 && x == x1) {
				if (checkOutingMap(y2 - 1, x2 - 1) && map[y2 - 1][x2] == 0 && map[y2 - 1][x2 - 1] == 0) return true;
				return false;
			}
			else {
				if (checkOutingMap(y1 + 1, x1 + 1) && map[y1 + 1][x1] == 0 && map[y1 + 1][x1 + 1] == 0) return true;
				return false;
			}
		}
		else {
			if (y == y1 && x == x1) {
				if (checkOutingMap(y2 - 1, x2 + 1) && map[y2][x2 + 1] == 0 && map[y2 - 1][x2 + 1] == 0) return true;
				return false;
			}
			else {
				if (checkOutingMap(y1 + 1, x1 - 1) && map[y1][x1 - 1] == 0 && map[y1 + 1][x1 - 1] == 0) return true;
				return false;
			}
		}
	}
	void go_cw(int y, int x) {
		if (mode == garo) {
			if (y == y1 && x == x1) {
				y2 += 1; x2 -= 1;
				mode = sero;
			}
			else {
				y1 -= 1; x1 += 1;
				mode = sero;
			}
		} else {
			if (y == y1 && x == x1) {
				y2 -= 1; x2 -= 1;
				swap(y1, y2);
				swap(x1, x2);
				mode = garo;
			}
			else {
				y1 += 1; x1 += 1;
				swap(y1, y2);
				swap(x1, x2);
				mode = garo;
			}
		}
	}
	void go_ccw(int y, int x) {
		if (mode == garo) {
			if (y == y1 && x == x1) {
				y2 -= 1; x2 -= 1;
				swap(y1, y2);
				swap(x1, x2);
				mode = sero;
			}
			else {
				y1 += 1; x1 += 1;
				swap(y1, y2);
				swap(x1, x2);
				mode = sero;
			}
		} else {
			if (y == y1 && x == x1) {
				y2 -= 1; x2 += 1;
				mode = garo;
			}
			else {
				y1 += 1; x1 -= 1;
				mode = garo;
			}
		}
	}
};

int visit[101][101][2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int solution(vector<vector<int>> board) {
	int answer = 0;
	my = mx = board.size();
	for (int i = 1; i <= my; i++) {
		for (int j = 1; j <= mx; j++) {
			map[i][j] = board[i-1][j-1];
		}
	}
	queue<drone> que;
	que.push(drone());
	visit[1][1][garo] = 1;

	while (!que.empty()) {
		drone now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			drone next = now;
			next.y2 += dy[i];
			next.y1 += dy[i];
			next.x2 += dx[i];
			next.x1 += dx[i];
			if (checkOutingMap(next.y2, next.x2) == false || checkOutingMap(next.y1, next.x1) == false) continue;
			if (map[next.y2][next.x2] || map[next.y1][next.x1]) continue;
			if (visit[next.y1][next.x1][next.mode]) continue;
			visit[next.y1][next.x1][next.mode] = 1;
			next.cnt++;
			if (next.y2 == my && next.x2 == mx) return next.cnt;
			if (next.y1 == my && next.x1 == mx) return next.cnt;
			que.push(next);
		}

		vector<pair<int, int>> xylist;
		xylist.push_back(make_pair(now.y1, now.x1));
		xylist.push_back(make_pair(now.y2, now.x2));
		for (int i = 0; i < 2; i++) {
			drone next = now;
			next.cnt++;
			if (next.can_cw(xylist[i].first, xylist[i].second)) {
				next.go_cw(xylist[i].first, xylist[i].second);
				if (visit[next.y1][next.x1][next.mode]) continue;
				visit[next.y1][next.x1][next.mode] = 1;
				que.push(next);
			}
		}
		for (int i = 0; i < 2; i++) {
			drone next = now;
			next.cnt++;
			if (next.can_ccw(xylist[i].first, xylist[i].second)) {
				next.go_ccw(xylist[i].first, xylist[i].second);
				if (visit[next.y1][next.x1][next.mode]) continue;
				visit[next.y1][next.x1][next.mode] = 1;
				que.push(next);
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board = { {0, 0, 0, 0, 0},{1, 1, 1, 0, 0},{0, 0, 0, 0, 0},{0, 0, 1, 1, 1 },{0, 0, 0, 0, 0} };
	cout << solution(board);
}