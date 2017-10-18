#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 100005;
int N, M, p[MAX], Rank[MAX], v[MAX][3];
long long weight[MAX];
bool V[MAX];
vector<pair<int, int> > adj[MAX];

void dfs(int cur, long long w) {
	V[cur] = true;
	weight[cur] = w;

	for (int i = 0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i].second;
		long long ww = adj[cur][i].first;

		if (!V[next])
			dfs(next, w + ww);
	}
}

int find(int a) {
	return a == p[a] ? a : p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (Rank[a] > Rank[b]) swap(a, b);
	p[a] = b;
	if (Rank[a] == Rank[b]) Rank[b]++;
}

int main() {


	while (1) {

		freopen("F.txt", "r", stdin);
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0) break;

		memset(adj, 0, sizeof(adj));
		memset(Rank, 0, sizeof(Rank));
		for (int i = 0; i<N; ++i)
			p[i] = i;

		int cnt = 0;
		for (int i = 0; i<M; ++i) {
			char op;
			int a, b, w;
			scanf(" %c%d%d", &op, &a, &b);
			--a, --b;
			if (op == '!') {
				scanf("%d", &w);
				adj[b].emplace_back(w, a);
				adj[a].emplace_back(-w, b);
				merge(a, b);
			}
			else {
				v[cnt][0] = find(a) == find(b);
				v[cnt][1] = a;
				v[cnt][2] = b;
				cnt++;
			}
		}

		memset(V, 0, sizeof(V));
		memset(weight, 0, sizeof(weight));

		for (int i = 0; i<N; ++i)
			if (!V[i])
				dfs(i, 0);

		for (int i = 0; i<cnt; ++i) {
			if (v[i][0]) printf("%lld\n", -weight[v[i][2]] + weight[v[i][1]]);
			else printf("UNKNOWN\n");
		}
	}

	return 0;
}
