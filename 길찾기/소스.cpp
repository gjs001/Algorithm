#include <iostream>
#include <vector>
using namespace std;


int dfs(int cur, int* visit, vector<vector<int> > &edge)
{
	visit[cur] = 1;
	if (cur == 99) return 1;
	for (int i = 0; i<edge[cur].size(); i++)
	{
		if (visit[edge[cur][i]]) continue;
		if (dfs(edge[cur][i], visit, edge)) return 1;
	}
	return 0;
}

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int n;
		
		cin >> n >> n;
		vector<vector<int>> edge;
		edge.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			int s, e;
			cin >> s >> e;
			edge[s].push_back(e);
		}
		int visit[101] = {};
		int ans = dfs(0, visit, edge);
		cout << "#" << t << " " << ans << "\n";
	}
}