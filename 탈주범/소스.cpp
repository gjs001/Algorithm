#include <iostream>
#include <queue>
using namespace std;
int dy[4] = { -1,0,1,0 }; int dx[4] = { 0,1,0,-1 };
int shape_check[8][4] = { { 1,1,1,1 },{ 0,0,0,0 },{ 0,1,0,1 },{ 1,0,1,0 },{ 0,0,1,1 },{ 1,0,0,1 },{ 1,1,0,0 },{ 0,1,1,0 } };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int h, w, sy, sx, l, ans = 0, cnt = 0;
		cin >> h >> w >> sy >> sx >> l;
		int map[101][101] = {};
		int visit[101][101] = {};
		for (int i = 0; i < h; i++)	for (int j = 0; j < w; j++)	cin >> map[i][j];
		queue<int> que;
		que.push(sy*w + sx);
		visit[sy][sx] = 1;
		while (!que.empty() && cnt < l)
		{
			int size = que.size();
			cnt++;
			while (size--)
			{
				int y = que.front() / w;
				int x = que.front() % w;
				que.pop();
				ans++;
				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || ny >= h || nx < 0 || nx >= w || shape_check[map[y][x]][i] || shape_check[map[ny][nx]][(i + 2) % 4] || visit[ny][nx]) continue;
					visit[ny][nx] = 1;
					que.push(ny*w + nx);
				}
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}