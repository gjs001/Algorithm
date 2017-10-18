#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
char map[13][7];
int visit[13][7];
vector<int> eraselist;
void bfs(int sy, int sx)
{
	queue<int> que;
	char tyle = map[sy][sx];
	que.push(sy * 6 + sx);
	int res = 0;
	visit[sy][sx] = 1;
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		int y = now / 6;
		int x = now % 6;
		eraselist.push_back(now);
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || map[ny][nx] != tyle || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			que.push(ny * 6 + nx);
		}
		res++;
	}
	if (res < 4) {
		for (int i = 0; i < res; i++) eraselist.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	 // 입력부
	for (int i = 0; i < 12; i++)
		cin >> map[i];
	int ans = 0;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		eraselist.clear();
		for (int i = 0; i < 12; i++) // 탐색
		{
			for (int j = 0; j < 6; j++)
			{
				if (!visit[i][j] && map[i][j] != '.') bfs(i, j);
			}
		}

		//삭제
		int size = eraselist.size();
		for (int i = 0; i < size; i++)
		{
			map[eraselist[i] / 6][eraselist[i] % 6] = '.';
		}
		if (size == 0)
		{
			break;
		}
		else
		{
			ans++;
		}
		//맵 재정렬(내리기)
		for (int j = 0; j < 6; j++)
		{
			int gap = 0;
			for (int i = 11; i >=0; i--)
			{
				if (map[i][j] == '.') gap++;
				else if(gap) {
					map[i + gap][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}

	}
	cout << ans;
}