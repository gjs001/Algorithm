#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
#define pii pair<int,int>


int graph[501][501];
int ox[4] = { 1 , -1, 0, 0 };
int oy[4] = { 0, 0 ,1,-1 };
int n, m;
int dp[501][501];
bool visit[501][501];

int dfs(int curx, int cury) {

	if (curx == n - 1 && cury == m - 1) return 1;
	if (dp[curx][cury] != -1) return dp[curx][cury];
	dp[curx][cury] = 0;
	int size = graph[curx][cury];
	for (int i = 0; i < 4; i++) {
			int newx = curx + ox[i];
			int newy = cury + oy[i];
			if ( newx >= 0 && newx < n && newy >= 0 && newy < m) {
				if (size > graph[newx][newy] && !visit[newx][newy]) {
					visit[newx][newy];
					dp[curx][cury] += dfs(newx, newy);
				}
			}
		}
	return dp[curx][cury];
		
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	dfs(0,0);
	cout << dp[0][0];
}