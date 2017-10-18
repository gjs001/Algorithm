#include <iostream>
#include <algorithm>


using namespace std;

typedef pair<int, int> P;
#define INF 987654321

int dy[8] = {-1,1,2,2,1,-1,2,-2};
int dx[8] = {2,2,1,-1,-2,-2,-1,1};
int n;
P target;
int visit[307][307];
int dp[307][307];
int dist[307][307];


int dfs(P oper, int d, int dir) {
	int &ret = dp[oper.first][oper.second];
	if (oper == target) {
		return 0;
	}
	for(int i = 0; i < 8; i++) {
		int ny = oper.first + dy[i];
		int nx = oper.second + dx[i];
		if (ny < 0 || ny > target.first + 5 || nx < 0 || nx > target.second + 5 || visit[ny][nx] || dist[ny][nx] <= d +1 || ((dir / 2) * 2 + 4) % 8 == i || ((dir / 2) * 2 + 5) % 8 == i) continue;
		dist[ny][nx] = d + 1;
		visit[ny][nx] = 1;	
		ret = min(ret,dfs(P(ny, nx), d +1, i)+1);
		visit[ny][nx] = 0;
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = INF;
				dist[i][j] = INF;
			}
		}
		P start;
		cin >> start.first >> start.second;
		cin >> target.first >> target.second;
		visit[start.first][start.second] = 1;
		dist[start.first][start.second] = 0;
		cout << dfs(start, 0, -1) << "\n";
		visit[start.first][start.second] = 0;
	}

}