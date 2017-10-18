#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


char graph[105][105];
int visit[105][105];
int key[30];
int nok = 0;
int t, h, w;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue<int> que;
int m_que[10000];
int head, tail, qsize;
vector<int> wall[30];
void que_push(int data)
{
	m_que[tail++] = data;
	if (tail == 10000) tail = 0;
	qsize++;
}
int que_front()
{
	return m_que[head];
}
void que_pop()
{
	head++;
	if (head == 10000) head = 0;
	qsize--;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t)
	{
		cin >> h >> w;
		memset(key, 0, sizeof(key));
		nok = 0;
		for (int i = 0; i < 26; i++)
		{
			wall[i].clear();
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> graph[i][j];
				if (graph[i][j] <= 'Z' && graph[i][j] >= 'A')
				{
					wall[graph[i][j] - 'A'].push_back(i*(w + 2) + j);
				}
			}
		}
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (j == 0 || j == w + 1 || i == 0 || i == h + 1)
					graph[i][j] = '.';
			}
		}

		char tmp[28];
		cin >> tmp;
		if (tmp[0] != '0') {
			for (int i = 0; i < strlen(tmp); i++)
			{
				key[tmp[i] - 'a'] = ++nok;
			}
		}

		int ans = 0;
		que_push(0);
		visit[0][0] = t;
		w += 2;
		h += 2;
		while (qsize)
		{
			int y = que_front() / w;
			int x = que_front() % w;
			que_pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w || graph[ny][nx] == '*' || visit[ny][nx] == t) continue;
				if (graph[ny][nx] == '$')
				{
					ans++;
					graph[ny][nx] = '.';
					visit[ny][nx] = t;
					que_push(ny*w + nx);
				}
				else if (graph[ny][nx] <= 'Z' && graph[ny][nx] >= 'A')
				{
					if (key[graph[ny][nx] - 'A'])
					{
						visit[ny][nx] = t;
						que_push(ny*w + nx);
					}
					visit[ny][nx] = t;
				}
				else if (graph[ny][nx] <= 'z' && graph[ny][nx] >= 'a' && key[graph[ny][nx] - 'a'] == 0)
				{
					key[graph[ny][nx] - 'a'] = ++nok;
					int size = wall[graph[ny][nx] - 'a'].size();
					int cur = 0;
					for (int i = 0; i < size; i++)
					{
						cur = wall[graph[ny][nx] - 'a'][i];
						if (visit[cur / w][cur%w] == t) que_push(cur);
					}
					que_push(ny*w + nx);
				}
				else
				{
					visit[ny][nx] = t;
					que_push(ny*w + nx);
				}
			}

		}
		cout << ans << "\n";
		t--;
	}
}