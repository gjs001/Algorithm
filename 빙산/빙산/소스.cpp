#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int w, h;
int icenum;
int day;
int map[301][301];
int tmp[301][301];
int visit[301][301];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int idx;
queue<PP> que[2];

int countice(P now) {
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int ny = now.first + dy[i];
		int nx = now.second + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w || visit[ny][nx] || !map[ny][nx]) continue;
		visit[ny][nx] = 1;
		cnt += countice(P(ny, nx));
	}
	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				que[idx].push(PP(map[i][j], P(i, j)));
				icenum++;
			}
		}
	}
	while (que[0].size() || que[1].size()) {
		memset(tmp, -1, sizeof(tmp));
		while (que[idx].size()) {
			PP now = que[idx].front();
			que[idx].pop();
			int nice = 0;
			for (int i = 0; i < 4; i++) {
				int ny = now.second.first + dy[i];
				int nx = now.second.second + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || !map[ny][nx]) {
					nice++;
				}
			}
			if (now.first - nice > 0) {
				now.first -= nice;
				que[!idx].push(now);
				map[now.second.first][now.second.second] = now.first;
			}
			else {
				tmp[now.second.first][now.second.second] = 0;
				icenum--;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (tmp[i][j] == -1) continue;
				map[i][j] = tmp[i][j];
			}
		}
		day++;
		if (que[!idx].empty()) {
			break;
		}
		visit[que[!idx].front().second.first][que[!idx].front().second.second] = 1;
		int nc = countice(que[!idx].front().second);
		if (nc != icenum) {
			cout << day;
			return 1;
		}
		memset(visit, 0, sizeof(visit));

		idx = !idx;

	}
	cout << 0;
}