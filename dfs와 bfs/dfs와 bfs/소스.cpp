#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

int visit[1001];
int edge[1001][1001];


void dfs(int now) {

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && edge[now][i]) {
			cout << i << " ";
			visit[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> que;
	que.push(start);
	visit[start] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i] || !edge[now][i]) continue;
			cout << i << " ";
			visit[i] = 1;
			que.push(i);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	visit[s] = 1;
	cout << s << " ";
	dfs(s);
	memset(visit, 0, sizeof(visit));
	cout << "\n";
	visit[s] = 1;
	cout << s << " ";
	bfs(s);

}