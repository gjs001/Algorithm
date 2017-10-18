#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int visit[10001];
int finished[10001];
vector<vector<int> > edge;
vector<vector<int > > compo;
int cnt;
int snt;
int num;
stack<int> st;
int dfs(int v) {
	
	visit[v] = num++;
	st.push(v);
	bool can_up = 0;
	int result = visit[v];
	int size = edge[v].size();
	for (int i = 0; i < size; i++) {
		int next = edge[v][i];
		if (finished[next]) continue;
		if (visit[next] == 0) result = min(result, dfs(next));
		result = min(result, visit[next]);
	}

	if (result == visit[v]) {
		vector<int> tmp;
		while (1){
			int t = st.top();
			tmp.push_back(t);
			finished[t] = 1;
			st.pop();
			if (t == v)break;
		}
		sort(tmp.begin(), tmp.end());
		tmp.push_back(-1);
		compo.push_back(tmp);
		cnt++;
	
	}

	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> v >> e;
	edge.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if(!visit[i])dfs(i);
	}
	sort(compo.begin(), compo.end());
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		int j = 0;
		while (compo[i][j] != -1) {
			cout << compo[i][j] << " ";
			j++;
		}
		cout << compo[i][j] << "\n";
	}
	
}
