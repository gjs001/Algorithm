
#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;
#define INF 987654321
#define black 10000
#define min(a,b) ((a) < (b))?(a):(b)

typedef pair<int, int> P;
typedef pair<int, P> PP;
priority_queue<PP,vector<PP>,greater<PP>> que;

int n;
int dist[51][51];
int map[51][51];
int visit[51][51];
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
			if (!map[i][j]) map[i][j] = black;
			dist[i][j] = INF;
		}
	}
	que.push(PP(0, P(0, 0)));
	while (que.size()) {
		PP now = que.top();
		que.pop();
		if (now.second.first == n - 1 && now.second.second == n - 1) {
			ans = now.first / black;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.second.first + dy[i];
			int nx = now.second.second + dx[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || dist[ny][nx] < now.first + map[ny][nx] || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			dist[ny][nx] = min(dist[ny][nx], now.first + map[ny][nx]);
			que.push(PP(dist[ny][nx], P(ny, nx)));
		}
	}

	printf("%d", ans);
}