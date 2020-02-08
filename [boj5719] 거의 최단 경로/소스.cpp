#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

vector<pii> path[501];
vector<pii> revpath[501];
int dist[501];
int del[501][501];
int n, m, s, d;

int search()
{
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pii, vector<pii>, greater<pii>> que;
	dist[s] = 0;
	que.push(pii(0, s));
	int minimal = -1;
	while (!que.empty())
	{
		pii now = que.top();
		que.pop();
		if (now.second == d && minimal == -1)
		{
			minimal = now.first;
		}
		else
		{
			for (auto i : path[now.second])
			{
				if (del[now.second][i.second]) continue;
				if (dist[now.second] + i.first < dist[i.second])
				{
					dist[i.second] = dist[now.second] + i.first;
					que.push(pii(dist[i.second], i.second));
				}
			}
		}
	}
	return minimal;
}

void del_path()
{
	queue<int> que;
	que.push(d);
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (auto i : revpath[now])
		{
			if (dist[i.second] + i.first == dist[now])
			{
				del[i.second][now] = 1;
				que.push(i.second);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		cin >> s >> d;

		for (int i = 0; i < n; i++) {path[i].clear(); revpath[i].clear();}
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			path[a].push_back(pii(c, b));
			revpath[b].push_back(pii(c,a));
		}
		memset(del, 0, sizeof(del));
		int minimal = search();
		search();
		del_path();
		int answer = search();
		cout << answer << "\n";
	}
}