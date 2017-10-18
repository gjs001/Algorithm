#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, answer;
char map[301][301];
int cnt[301][301];
int visit[301][301];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void check()
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			for (int k = 0; k < 8; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == '.') continue;
				tmp++;
			}
			cnt[i][j] = tmp;
		}
	}
}

void bfs(int sy, int sx)
{
	queue<int> que;
	que.push(sy*n + sx);
	visit[sy][sx] = 1;
	while (!que.empty())
	{
		int y = que.front() / n;
		int x = que.front() % n;
		que.pop();
		if (cnt[y][x]) continue;
		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visit[ny][nx] || map[ny][nx] == '*') continue;
			visit[ny][nx] = 1;
			que.push(ny*n + nx);

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> map[i];
		check();
		answer = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j] && cnt[i][j] == 0 && map[i][j] !='*')
				{
					bfs(i, j);
					answer++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j] && map[i][j] != '*')
				{
					answer++;
				}
			}
		}
		cout << "#" << tc << " " << answer << "\n";
	}
}