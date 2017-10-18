#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

#define max(a,b) ((a) > (b))?(a):(b)

int w, h;
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[51][51];
int visit[51][51];
int dp[51][51];

int dfs(int now, int depth) {
	int y = now / w;
	int x = now % w;
	int cur = now;

	int &ret = dp[y][x];
	if (ret) return ret;
	int sum = 0;
	int cnt = 0;
	
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i] * (map[y][x] - '0');
			int nx = x + dx[i] * (map[y][x] - '0');
			if (nx < 0 || ny < 0 || nx >= w || ny >= h || map[ny][nx] == 'H') continue;
			if (visit[ny][nx]) return -1;
			cnt++;
			visit[ny][nx] = 1;
			int tmp = dfs(ny*w + nx, depth + 1);
			if (tmp == -1) return -1;
			else sum = max(sum,tmp + 1);
			visit[ny][nx] = 0;
		}
		if (cnt == 0)
			return ret = 1;
		return ret = sum;
}


int main() {
	cin >> h >> w;
	for(int i=0;i<h;i++)
	{
		for (int j = 0; j < w; j++) 
		{
			scanf(" %1c", &map[i][j]);
		}
	}
	
	visit[0][0] = 1;
	cout << dfs(0,0);
}

