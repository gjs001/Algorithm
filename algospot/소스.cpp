#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>


#define INF 987654321
#define min(a,b) ((a) < (b) ? (a):(b))
using namespace std;

int visit[101][101];
int graph[101][101];
int dist[101][101];
int N, M;
int ans;
void dijkstra() {
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
	que.push(make_pair(1,make_pair(1, 1)));
	visit[1][1] = true;
	dist[1][1] = 0;
	while (que.top().second.second != N || que.top().second.first != M) {

		

		int x = que.top().second.first;
		int y = que.top().second.second;
		que.pop();
		if (x - 1 > 0 && !visit[x - 1][y]) {
			dist[x - 1][y] = min(dist[x-1][y],dist[x][y] + graph[x - 1][y]);
			que.push(make_pair(dist[x-1][y],make_pair(x - 1, y)));
			visit[x - 1][y] = 1;
		}
		if (x + 1 <= M && !visit[x + 1][y]) {
			dist[x + 1][y] = min(dist[x + 1][y], dist[x][y] + graph[x + 1][y]);
			que.push(make_pair(dist[x + 1][y], make_pair(x + 1, y)));
			visit[x + 1][y] = 1;
		}
		if (y - 1 > 0 && !visit[x][y - 1]) {
			dist[x][y - 1] = min(dist[x][y -1], dist[x][y] + graph[x][y-1]);
			que.push(make_pair(dist[x][y-1],make_pair(x, y-1)));
			visit[x][y-1] = 1;
		}
		if (y +1 <= N && !visit[x][y + 1]) {
			dist[x][y + 1] = min(dist[x][y + 1],dist[x][y] + graph[x][y + 1]);
			que.push(make_pair(dist[x][y+1],make_pair(x, y + 1)));
			visit[x][y + 1] = 1;
		}
	}

}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp;
			scanf("%1d", &tmp);
			if (tmp) graph[j][i] = 10000;
			else graph[j][i] = 1;
			dist[j][i] = INF;
		}
	}
	dijkstra();
	ans = dist[M][N] / 10000;
	cout << ans;

}