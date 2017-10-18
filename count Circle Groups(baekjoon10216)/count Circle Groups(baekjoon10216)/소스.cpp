#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
typedef pair<int, P> PP;
int t, n;
int ans;
int map[5001][5001];
bool visit[5001][5001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int chain[3001][3001];
int cvisit[3001];
void dfs(int now, int size) {
	cvisit[now] = 1;
	
	for (int i = 0; i < size; i++) {
		if (chain[now][i] && !cvisit[i]) {
			dfs(i, size);
		}
	}
	return;
}


int main() {
	cin >> t;

	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		vector<PP> v;

		memset(cvisit, 0, sizeof(cvisit));
		memset(chain, 0, sizeof(chain));
		for (int i = 0; i < n; i++) {
			int y, x, r;
			scanf("%d %d %d", &x, &y, &r);
			v.push_back(PP(r, P(y, x)));
		}
		
		
		for (int i = 0; i < n; i++)
		{
			int y = v[i].second.first;
			int x = v[i].second.second;
			int r = v[i].first;
			for (int j = i+1; j < n; j++)
			{
				int nr = v[j].first;
				int ny = v[j].second.first;
				int nx = v[j].second.second;

				if ((x - nx)*(x - nx) + (y - ny)*(y - ny) <= (r + nr)*(r + nr)) {
					chain[i][j] = 1;
					chain[j][i] = 1;
				}
			}
			
		}

		for(int i = 0; i <n ; i++) {
			if (!cvisit[i]) { 
				dfs(i, n);
				ans++; }
		}
		cout << ans << "\n";
	}
}