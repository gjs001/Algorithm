#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n, m, k;
typedef struct edge
{
	int e;
	int c;
	int d;
	edge() {};
	edge(int _e, int _c, int _d) { e = _e; c = _c; d = _d; }
}edge;

bool operator <(edge a, edge b)
{
	return a.d > b.d;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n >> m >> k;
		vector<vector<edge>> elist(n + 1);
		priority_queue<edge> que;
		//vector<int> dist(n + 1, 987654321);
		vector<vector<int>> visit(n + 1);
		for (int i = 1; i <= n; i++)visit[i].resize(10001, 987654321);
		for (int i = 0; i < k; i++)
		{
			edge tmp;
			int s;
			cin >> s >> tmp.e >> tmp.c >> tmp.d;
			elist[s].push_back(tmp);
		}
		que.push(edge(1, 0, 0));
		int ans_dist = 987654321;

		while (!que.empty())
		{
			edge now = que.top();
			que.pop();
			if (now.e == n && now.c <= m)
			{
				if (ans_dist > now.d)
				{
					ans_dist = now.d;
				}
			}
			if (visit[now.e][now.c] < now.d) continue;
			for (auto r : elist[now.e])
			{
				int nc = now.c + r.c;
				if (nc > m) continue;
				if (visit[r.e][nc] > now.d + r.d)
				{
					visit[r.e][nc] = now.d + r.d;
					que.push(edge(r.e, nc, now.d + r.d));
				}
			}
		}
		if (ans_dist == 987654321) cout << "Poor KCM\n";
		else cout << ans_dist << "\n";
	}
}