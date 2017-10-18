#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
int map[21][21];
int dx[4] = { 1,-1 ,-1,1};
int dy[4] = { 1,1 ,-1,-1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n;
		int ans = -1;
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		int cap = n * 2;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				for (int i = 1; i <= cap; i++)
				{
					int rny = y + dy[0]*i;
					int rnx = x + dx[0]*i;
					if (rny < 0 || rny >= n || rnx < 0 || rnx >= n) break;
					for (int j = 1; j <= cap; j++)
					{
						int lny = y + dy[1] * j;
						int lnx = x + dx[1] * j;
						if (lny < 0 || lny >= n || lnx < 0 || lnx >= n) break;
						int bny = lny + dy[0] * i;
						int bnx = lnx + dx[0] * i;
						if (bny < 0 || bny >= n || bnx < 0 || bnx >= n) break;
						int ret = 0;
						int cy = y;
						int cx = x;
						int visit[401] = {};
						int flag = 0;
						while (cy < rny)
						{
							if (visit[map[cy][cx]])
							{
								flag = 1; break;
							}
							ret++;
							visit[map[cy][cx]] = 1;
							cy += dy[0];
							cx += dx[0];
						}
						if (flag) continue;
						while (cy < bny)
						{
							if (visit[map[cy][cx]])
							{
								flag = 1; break;
							}
							ret++;
							visit[map[cy][cx]] = 1;
							cy += dy[1];
							cx += dx[1];
						}
						if (flag) continue;
						while (cy > lny)
						{
							if (visit[map[cy][cx]])
							{
								flag = 1; break;
							}
							ret++;
							visit[map[cy][cx]] = 1;
							cy += dy[2];
							cx += dx[2];
						}
						if (flag) continue;
						while (cy > y)
						{
							if (visit[map[cy][cx]])
							{
								flag = 1; break;
							}
							ret++;
							visit[map[cy][cx]] = 1;
							cy += dy[3];
							cx += dx[3];
						}
						if (flag) continue;
						ans = max(ans, ret);
					
					}
				}
			}
		}
		cout << "#" << testcase << " " << ans << "\n";
	}
}