#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int maxn, lcnt, vcnt;
bool visit[51][51];
char graph[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int start) {
	int sx = start % m;
	int sy = start / m;
	if (graph[sy][sx] == 'W') return;
	visit[sy][sx] == 1;
	queue<pair<pair<int,int>,int>> que;
	que.emplace(make_pair(sx, sy),0);
	while (que.size()) {
		int curx = que.front().first.first;
		int cury = que.front().first.second;
		int now = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			
			if (cury + dy[i] >= 0 && cury + dy[i] < n && curx +dx[i] >= 0 && curx +dx[i] < m) {
				if (graph[cury + dy[i]][curx + dx[i]] == 'L' && !visit[cury + dy[i]][curx + dx[i]]) {
					que.emplace(make_pair(curx + dx[i], cury + dy[i]),now+1);
					visit[cury + dy[i]][curx + dx[i]] = 1;
				}
			}
		}
		if (maxn < now) maxn = now;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			scanf("%s", &graph[i]);
	}
	for (int i = 0; i < n*m; i++) {
		memset(visit, 0, sizeof(visit));
		bfs(i);
	}
	cout << maxn;
}
