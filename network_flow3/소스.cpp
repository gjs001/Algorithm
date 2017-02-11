#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

priority_queue<pair<int, int>> que;
int graph[2002][2002];
int visit[2002];
int parent[2002];
int start = 0;
int endv;
int N, M, K;

bool dfs(int cur) {
	if (cur == endv) return true;
	visit[cur] = 1;
	for (int i = 0; i <= endv; i++) {
		if (!visit[i] && graph[cur][i] > 0) {
			parent[i] = cur;
			if (dfs(i)) return true;
		}
	}
	return false;
}
void tracking(int cur) {
	if (cur == start) return;
	int par = parent[cur];
	graph[par][cur]--;
	graph[cur][par]++;
	tracking(par);
}

int main() {
	cin >> N >> M >> K;
	endv = N + M + 1;
	int work[2002][2];
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		graph[start][i] = 1;
		que.push(make_pair(tmp, i));
		for (int j = 1; j <= tmp; j++) {
			int tar;
			scanf("%d", &tar);
			graph[i][tar + N] = 1;
		}

	}
	for (int i = 0; i < K; i++) {
		graph[start][que.top().second] = 2;
		que.pop();
	}

	for (int i = N + 1; i <= N + M; i++) graph[i][endv] = 1;

	int cnt = 0;

	while (dfs(start)) {
		cnt++;
		tracking(endv);
		memset(visit, false, sizeof(visit));
	}

	printf("%d\n", cnt);
}
