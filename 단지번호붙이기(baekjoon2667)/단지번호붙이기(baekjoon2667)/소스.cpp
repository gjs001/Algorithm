#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[26][26];
int map[26][26];
int ans[1001];


int main() {
	cin >> n;
	queue<P> que;
	bool flag = 0;
	int onum = 0;
	for (int i = 0; i < n; i++) {
		char tmp;
		scanf("%c", &tmp);
		for (int j = 0; j < n; j++) {
			map[i][j] = getchar()- '0';
			if (map[i][j] == 1) {
				if (!flag) {
					flag = 1;  que.push(P(i, j));
					visit[i][j] = 1;
				}
				onum++;
			}

		}
	}
	flag = 0;
	int now_num = 1;
	int cnt = 0;
	if (que.empty()) {
		cout << 0;
		return 0;
	}
	while (que.size()) {
		cnt++;
		while (que.size()) {
			P now = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];

				if (ny >= 0 && nx >= 0 && ny < n && nx < n && !visit[ny][nx] && map[ny][nx] == 1) {
					visit[ny][nx] = 1;
					que.push(P(ny, nx));
					map[ny][nx] = cnt;
					now_num++;
				}
			}
		}
		ans[cnt] = now_num;
		now_num = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					if (!flag) {
						flag = 1;  que.push(P(i, j));
						visit[i][j] = 1;
						map[i][j] = cnt + 1;
					}

				}

			}
		}
		flag = 0;
	}
	cout << cnt << "\n";
	sort(ans + 1, ans + cnt+1);
		for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << "\n";
	}
}
