#include <iostream>
#include <cstring>

using namespace std;

int p[205];
int n, m;

int find(int a)
{
	if (p[a] < 0) return a;
	else return p[a] = find(p[a]);
}

bool merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return true;
	if (p[pa] < p[pb]) swap(pa, pb);
	p[pb] += p[pa];
	p[pa] = pb;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			cin >> tmp;
			if(tmp) merge(i, j);
		}
	}
	int now;
	int prev;
	cin >> prev;
	for (int i = 0; i < m-1; i++) {
		cin >> now;
		if (find(now) != find(prev))
		{
			cout << "NO";
			return 0;
		}
		prev = now;
	}
	cout << "YES";
}