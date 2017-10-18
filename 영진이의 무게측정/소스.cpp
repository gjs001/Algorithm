#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m;
int dist[100001];
int p[100001];
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int find(int a)
{
	if (p[a] < 0) return a;
	dist[a] += dist[p[a]];
	int res = p[a] = find(p[a]);
	return res;
	
}

bool merge(int a, int b,int diff)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return true;
	
	if (p[pa] < p[pb])
	{
		swap(a, b);
		swap(pa, pb);
		diff = -diff;
	}
	dist[pa] = dist[b] + diff - dist[a];
	p[pb] += p[pa];
	p[a] = pb;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n >> m;
		cout << "#" << testcase << " ";
		memset(dist, 0, sizeof(dist));
		memset(p, -1, sizeof(p));
		for (int i = 0; i < m; i++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == '!')
			{
				int a, b, d;
				cin >> a >> b >> d;
				merge(a, b, d);
			}
			else {
				int a, b;
				cin >> a >> b;
				if (find(a) != find(b)) cout << "UNKNOWN ";
				else
				{
					cout << -dist[b] + dist[a] << " ";
				}
			}
		}
		cout << "\n";
		 
	}
}