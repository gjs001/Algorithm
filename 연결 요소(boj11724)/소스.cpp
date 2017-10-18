#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visit[1001];
int map[1001][1001];
queue<int> que;
bool bfs(int start) {
	if (visit[start]) return false;
	que.push(start);
	visit[start] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (map[now][i] && !visit[i]) {
				visit[i] = 1;
				que.push(i);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (bfs(i)) ans++;
	}
	cout << ans;
}