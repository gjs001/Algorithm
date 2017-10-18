#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
vector <int> nt[123456];
set<int> que;
int qu[123456];
int val[123456];
int cnt[123456];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i<m; i++) {
		scanf("%d%d", &u, &v);
		nt[v].push_back(u);
		cnt[u]++;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)que.insert(i);
	}
	int i = 0;
	while (!que.empty()) {
		int x = *que.rbegin();
		que.erase(x);
		qu[i++] = x;
		for (int j = 0; j<nt[x].size(); j++) {
			if (--cnt[nt[x][j]] == 0)que.insert(nt[x][j]);
		}
	}
	for (int i = 0; i<n; i++) {
		val[qu[i]] = n - i;
	}
	for (int i = 1; i <= n; i++) {
		printf(i != 1 ? " %d" : "%d", val[i]);
	}
	return 0;
}