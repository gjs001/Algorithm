#include <iostream>
#include <algorithm>

using namespace std;

int t,k,n;
int map[10][10];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int dfs(int y, int x)
{
	int curh = map[y][x];
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || map[ny][nx] >= curh) continue;
		
		ret = max(ret, dfs(ny, nx) + 1);
		
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n >> k;
		int maxh = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				maxh = max(maxh, map[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int ck = 0; ck <= k; ck++)
				{
					map[i][j] -= ck;
					for (int x = 0; x < n; x++)
					{
						for (int y = 0; y < n; y++)
						{
							if (map[y][x] != maxh) continue;
						
							ans = max(ans, dfs(y, x) + 1);
						
						}
					}
					map[i][j] += ck;
				}
			}
		}
		cout << "#" << testcase << " " << ans << "\n";
	}
}