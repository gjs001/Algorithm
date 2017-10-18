#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int, int> P;
long long dist[100001];
int p[100001];
int visit[100001];
int Rank[100001];
int ans[100001][3];
vector<P> edge[100005];
int n, m, t;
int cnt;
int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (Rank[a] > Rank[b]) swap(a, b);
	p[a] = b;
	if (Rank[a] == Rank[b]) Rank[b]++;
}

void dfs(int cur, long long depth) {

	int size = edge[cur].size();
	dist[cur] = depth;
	for (int i = 0; i < size; i++) {
		if (visit[edge[cur][i].first])continue;
		visit[edge[cur][i].first] = 1;
		long long nd = edge[cur][i].second;
		dfs(edge[cur][i].first, depth + nd);
	}
}


int main() {
	//ios::sync_with_stdio(false);

	freopen("F.in", "r", stdin);
	
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) return 0;
		memset(Rank, 0, sizeof(Rank));
		memset(p, -1, sizeof(p));

		memset(edge, 0, sizeof(edge));
		int cnt = 0;
		for (int i = 0; i < m; i++) {

			char cmd;
			scanf(" %c", &cmd);
			if (cmd == '!') {
				int s, e, d;
				scanf("%d %d %d", &s, &e, &d);
				merge(s, e);
				edge[s].push_back(P(e, -d));
				edge[e].push_back(P(s, d));
			
			}
			else if (cmd == '?') {
				int s, e;
				scanf("%d %d", &s, &e);
				ans[cnt][0] = find(s) == find(e);
				ans[cnt][1] = s;
				ans[cnt][2] = e;
				cnt++;
			}
		}

		memset(dist, 0, sizeof(dist));
		memset(visit, 0, sizeof(visit));
		for(int i=1;i<=n;i++)
			if (!visit[i]) {
				visit[i] = 1;
				dfs(i, 0);
			}
		for (int i = 0; i < cnt; i++) {
			if (!ans[i][0]) cout << "UNKNOWN\n";
			else {
				printf("%lld\n", dist[ans[i][1]] - dist[ans[i][2]]);
			}
		}
	}
}

