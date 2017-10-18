#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2000000000
typedef pair<int, int> P;
int t, n, m, w;

int dist[501];
int visit[501];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		vector<P> Marr[501];
		cin >> n >> m >> w;
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			visit[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			int s, e, l;
			cin >> s >> e >> l;
			Marr[s].push_back(P(e, l));
			Marr[e].push_back(P(s, l));
			
		}
		for (int i = 0; i < w; i++) {
			int s, e, l;
			cin >> s >> e >> l;
			Marr[s].push_back(P(e, -l));
		}
		bool minuscycle = false;
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto &p : Marr[j]) {
					int next = p.first;
					int d = p.second;
					if (dist[j] != INF && dist[next] > dist[j] + d) {
						dist[next] = dist[j] + d;
						if (i == n) minuscycle = true;
					}
				}
			}
		}
		if (minuscycle) cout << "YES\n";
		else cout << "NO\n";
	}
}