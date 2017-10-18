#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
int t, n, m;
int map[21][21];
int ans;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int cost[23];
queue<P > que;
int get_cost(int k)
{
	return (k*k) + (k - 1)*(k - 1);
}

int bfs(int sy, int sx, int k)
{
	int visit[21][21] = {};
	que.push(P(sy*n + sx, 1));
	visit[sy][sx] = 1;
	int total = get_cost(k);
	int now = 0;
	while (!que.empty())
	{
		int y = que.front().first / n;
		int x = que.front().first % n;
		int dist = que.front().second;
		que.pop();
		if (map[y][x])
		{
			now += m;
		}
		if (dist == k) continue;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			que.push(P(ny*n + nx, dist + 1));
		}

	}
	return now;

}

int move(int y, int x, int k, int prev)
{
	int now = prev;
	for (int i = k-1; i >= -k+1; i--)
	{
		int ny = y + i;
		int nx = x - ((k-1) - abs(i));
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || !map[ny][nx]) continue;
		now -= m;
	}
	for (int i = k-1; i >= -k+1; i--)
	{
		int ny = y + i;
		int nx = x + ((k-1) - abs(i))+1;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || !map[ny][nx]) continue;
		now += m;
	}
	return now;
}

int movey(int y, int x, int k, int prev)
{
	int now = prev;
	for (int i = k - 1; i >= -k + 1; i--)
	{
		int nx = x + i;
		int ny = y - ((k - 1) - abs(i));
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || !map[ny][nx]) continue;
		now -= m;
	}
	for (int i = k - 1; i >= -k + 1; i--)
	{
		int nx = x + i;
		int ny = y + ((k - 1) - abs(i)) + 1;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || !map[ny][nx]) continue;
		now += m;
	}
	return now;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
		for (int i = 1; i <= 22; i++) cost[i] = get_cost(i);
		for (int k = 1; k <= n + 1; k++)
		{
			int previ;
			for (int i = 0; i < n; i++)
			{
				int prev;
				if(i==0) previ = prev = bfs(i, 0, k);
				else previ = prev = movey(i-1,0, k,previ);
				if (prev >= cost[k]) ans = max(ans, prev / m);
				for (int j = 0; j < n-1; j++)
				{
					prev = move(i, j, k, prev);
					if (prev >= cost[k]) ans = max(ans, prev / m);
				}
			}
		}
		cout << "#" << testcase << " " << ans << "\n";
	}
}