#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
vector<vector<int>> edge;
int visit[100001];
int n;
double ans;
void dfs(int now, double per, double length) {
	int size = edge[now].size();
	int flag = 1;
	int rsize = 0;
	for (int i = 0; i < size; i++) {
		if (visit[edge[now][i]]) continue;
		rsize++;
	}
	for (int i = 0; i < size ; i++) {
		if (visit[edge[now][i]]) continue;
		flag = 0;
		visit[edge[now][i]] = 1;
		dfs(edge[now][i], per / rsize, length + 1);
	}
	if (flag) {
		ans += length * per;
	}
	return;
}

int main()
{
	
	cin >> n;
	edge.resize(n+1);
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}
	visit[1] = 1;
	dfs(1, 10000000000, 0);
	ans /= 10000000000;
	printf("%.15lf", ans);
}