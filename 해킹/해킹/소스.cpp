#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
int n, m;
//int visit[10001];
vector<bool> visit;
int ree[10001][2];
int ans[10001][2];
int real[10001];
int grp;
vector<int> dp;
vector<vector<int>> v;
queue<int> que;


int dfs(int start) {
	if (dp[start]) return dp[start];
	visit[start] = true;
	dp[start] += 1;
	
	for (int i = 0; i < v[start].size(); i++) {
		
		int there = v[start][i];
		if (!visit[there]) dp[start] += dfs(there);
		

	}
	return dp[start];
}


int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	dp.resize(n + 1);
		for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &e, &s);
		ree[s][1]++;
		ree[e][0]++;
		v[s].push_back(e);
	}
	for (int i = 1; i <= n; i++) {
		if (ree[i][0] == 0 && ree[i][1] == 0 ) continue;


		que.push(i);
	}
	int max = 0;
	int cnt = 0;
	while (que.size()) {
		visit = vector<bool>(n + 1, false);
		int now = que.front();
		que.pop();
		ans[cnt][0] = dfs(now);
		ans[cnt][1] = now;
		if (max < ans[cnt++][0]) max = ans[cnt-1][0];
	}
	int cnt2 = 0;
	for (int i = 0; i < cnt; i++) {
		if (max > ans[i][0]) continue;
		real[cnt2++] = ans[i][1];
	}

	sort(real, real + cnt2);
	for (int i = 0; i < cnt2; i++) printf("%d ", real[i]);
}