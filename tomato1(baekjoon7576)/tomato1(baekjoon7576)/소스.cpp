#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
struct tomato{
	int day;
	int y;
	int x;
};
int w, h;
int dx[4] = { 1, -1 ,0 ,0 };
int dy[4] = { 0,0,1,-1 };
int map[1001][1001];
queue<tomato> que;
bool visit[1001][1001];

int main() {
	cin >> w >> h;

	int tot = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				que.push(tomato{ 0,i,j });
				visit[i][j] = 1;
			
			}
			if (map[i][j] == 0) tot++;

		}
	}
	if (!tot) {
		cout << 0;
		return 0;
	}
	int max = 0;
	int ans = 0;
	while (que.size()) {
		tomato now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < h && nx < w && map[ny][nx] == 0 && !visit[ny][nx]) {
				visit[ny][nx] = 1;
				map[ny][nx] = 1;
				que.push(tomato{ now.day + 1,ny,nx });
				if (max < now.day + 1) max = now.day + 1;
				ans++;
			}
		}
	}
	if(ans == tot)	cout << max;
	else cout << -1;
}