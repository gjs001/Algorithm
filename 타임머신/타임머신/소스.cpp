#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

int n, m;
int dist[501];
typedef pair<int, int> P;

vector<vector<pair<int,int>>> edge;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	edge.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		edge[s].push_back(P(e, d));
	}
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	int cycle = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 1; j <= n; j++) {
			for (auto i : edge[j]) {
				if (dist[j] != INF && dist[j] + i.second < dist[i.first]) {
					dist[i.first] = dist[j] + i.second;
					if(k == n - 1){
						cycle = 1;
					}
				}
			}
		}
	}

	if (cycle) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if(dist[i] != INF) cout << dist[i] << "\n";
			else cout << "-1\n";
		}
	}

}