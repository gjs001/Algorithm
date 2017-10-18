#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Data {
	int x, y, dist;
	Data(int _x, int _y, int _d) :x(_x), y(_y), dist(_d) {};
};
int main()
{
	int n, map[100][100], num = 2;
	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };
	cin >> n;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			cin >> map[i][j];
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (map[i][j] == 1)
			{
				queue<Data> q;
				q.push(Data(j, i, 0));
				while (!q.empty())
				{
					int x = q.front().x;
					int y = q.front().y;
					q.pop();
					map[y][x] = num;
					for (int k = 0; k<4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && ny >= 0 && nx<n&&ny<n&&map[ny][nx] == 1)
							q.push(Data(nx, ny, 0));
					}
				}
				num++;
			}
	int ans = 987654321;
	bool chk[10000] = {};
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			int cur = map[i][j];
			if (cur && !chk[cur])
			{
				chk[cur] = true;
				queue<Data> q;
				q.push(Data(j, i, 0));
				bool visit[100][100] = {};
				visit[i][j] = true;
				while (!q.empty())
				{
					int x = q.front().x;
					int y = q.front().y;
					int dist = q.front().dist;
					q.pop();
					if (dist >= ans)
						continue;
					for (int k = 0; k<4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx<0 || ny<0 || nx >= n || ny >= n || visit[ny][nx])
							continue;
						visit[ny][nx] = true;
						if (map[ny][nx] == 0)
						{
							if (dist + 1<ans)
								q.push(Data(nx, ny, dist + 1));
						}
						else if (map[ny][nx] != cur)
						{
							ans = min(ans, dist);
							break;
						}
						else if(map[y][x]  )
							q.push(Data(nx, ny, dist));
					}
				}
			}
		}
	if (ans == 987654321) ans << 0;
	else 	cout << ans;
	return 0;
}