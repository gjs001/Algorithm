#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
char map[11][11];
int visit[11][11][11][11];
int rcur, bcur;
int h, w;
int hole;
typedef pair<int, int> P;
typedef pair<int, P> PP;
queue<PP> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R') rcur = i*w + j;
			if (map[i][j] == 'B') bcur = i*w + j;
			if (map[i][j] == 'O') hole = i*w + j;
		}
	}
	que.push(PP(0,P(-1, rcur)));
	que.push(PP(0,P(-1, bcur)));
	int ans = -1;
	visit[rcur/w][rcur%w][bcur/w][bcur%w] = 1;
	while (!que.empty())
	{
		PP r = que.front();
		que.pop();
		PP b = que.front();
		que.pop();
		if (r.first >= 10) break;

		int dir = r.second.first;
		int ry = r.second.second / w;
		int rx = r.second.second % w;
		int rd = r.first;
		int by = b.second.second / w;
		int bx = b.second.second % w;
		int bd = b.first;
		
		
		for (int i = 0; i < 4; i++)
		{
			if (dir == 1 && i % 2 == 1) continue;
			if (dir == 0 && i % 2 == 0) continue;
			bool isbluehole = 0;
			int nby = by + dy[i];
			int nbx = bx + dx[i];
			while (nby >= 0 && nby < h && nbx >= 0 && nbx < w && map[nby][nbx] != '#')
			{
				if (map[nby][nbx] == 'O') {
					isbluehole = 1;
					break;
				}
				nby += dy[i];
				nbx += dx[i];
			}
			nby -= dy[i];
			nbx -= dx[i];
			if (isbluehole) continue;
			int nry = ry + dy[i];
			int nrx = rx + dx[i];
			while (nry >= 0 && nry < h && nrx >= 0 && nrx < w && map[nry][nrx] != '#')
			{
		
				if (map[nry][nrx] == 'O') {
					ans = rd+1;
					break;
				}
				nry += dy[i];
				nrx += dx[i];
			}
			nry -= dy[i];
			nrx -= dx[i];
			if (ans != -1) break;

			if (nry == nby && nrx == nbx)
			{
				if (abs(nry - ry) + abs(nrx - rx) > abs(nby - by) + abs(nbx - bx))
				{
					nry -= dy[i];
					nrx -= dx[i];
				}
				else {
					nby -= dy[i];
					nbx -= dx[i];
				}
			}
			if (!visit[nry][nrx][nby][nbx]) {
				que.push(PP(rd + 1, P(i % 2, nry*w + nrx)));
				que.push(PP(rd + 1, P(i % 2, nby*w + nbx)));
				visit[nry][nrx][nby][nbx] = 1;
			}

		}
		if (ans != -1) break;
	}
	cout << ans;
}