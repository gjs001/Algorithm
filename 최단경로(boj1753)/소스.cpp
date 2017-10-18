#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

#define INF 987654321

typedef pair<int, int> P;

int v, e;

int start;
vector<vector<pair<int, int>>> edge;


int main() {
	ios::sync_with_stdio(false);
	cin >> v >> e >> start;
	vector<int> dist(v + 1, INF);
	edge.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(P(c, b));
	}
	
	priority_queue<P,vector<P>, greater<P>> que;
	que.push(P(0, start));
	dist[start] = 0;
	while (!que.empty()) {
		P now = que.top();
		que.pop();
		int size = edge[now.second].size();
		for (int i = 0; i < size; i++) {
			if (dist[now.second] + edge[now.second][i].first < dist[edge[now.second][i].second]) {
				dist[edge[now.second][i].second] = dist[now.second] + edge[now.second][i].first;
				que.push(P(dist[edge[now.second][i].second], edge[now.second][i].second));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] != INF) cout << dist[i] << "\n";
		else cout << "INF\n";
	}

}