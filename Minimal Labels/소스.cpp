#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> P;
int n, m;
vector<vector<int> > Edge;

int indegree[100001];
int ans[100001];
int val[112345];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> visit(n + 1, 0);
	Edge.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		Edge[s].push_back(e);
		indegree[e]++;
	}
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			que.push(i);
			visit[i] = 1;
		}
	}
	int cnt = 1;
	while (!que.empty()) {
		int now = que.top();
		que.pop();
		ans[now] = cnt++;
		int size = Edge[now].size();
		for (int i = 0; i < size; i++) {
			if (visit[Edge[now][i]]) continue;
			indegree[Edge[now][i]]--;
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && indegree[i] == 0) {
				que.push(i);
				visit[i] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}