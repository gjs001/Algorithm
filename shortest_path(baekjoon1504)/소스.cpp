#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

#define INF 2100000000
#define pii pair<long long int,int>
#define min(a,b) ((a) < (b) ? (a) : (b))
int v, e;
int T1, T2;
int graph[801][801];
long long dist[801];

void dajikstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i = 1; i <= v; i++) dist[i] = INF;
	dist[s] = 0;
	que.push(make_pair(0,s));
	int cur;
	int cdist;
	while (que.size()) {
		cur = que.top().second;
		cdist = que.top().first;
		que.pop();
		for (int i = 1; i <= v; i++) {
			if (graph[cur][i] != 0) {
				int tmp = min(dist[i], cdist + graph[cur][i]);
				if (graph[cur][i] == INF || dist[i] != tmp) {
					dist[i] = min(dist[i], cdist + graph[cur][i]);
					que.push(make_pair(dist[i], i));
				}
			}

		}
	
	}
	
}

int main() {
	long long ans1, ans2;
	long long T1_to_1, T1_to_T2, T1_to_v;
	long long T2_to_1, T2_to_T1, T2_to_v;
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		int tmp1, tmp2, tmp3;
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		if (graph[tmp1][tmp2] == 0 || graph[tmp1][tmp2] > tmp3) {
			graph[tmp1][tmp2] = tmp3;
			graph[tmp2][tmp1] = tmp3;
		}
	}
	scanf("%d %d", &T1, &T2);

	dajikstra(T1);
	T1_to_1 = dist[1];
	T1_to_T2 = dist[T2];
	T1_to_v = dist[v];
	dajikstra(T2);
	T2_to_1 = dist[1];
	T2_to_v = dist[v];

	ans1 = T1_to_1 + T1_to_T2 + T2_to_v;
	ans2 = T2_to_1 + T1_to_T2 + T1_to_v;
	if (ans1 >= INF && ans2 >= INF)	cout << -1;
	else cout << min(ans1, ans2);





}