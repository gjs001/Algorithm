#include <iostream>
#include <cstring>
using namespace std;

#define FULL -2
int n, m;
int p[300001];

int find(int a)
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

int merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return p[pa];
	p[pa] = pb;
	return p[pb];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			if (p[find(a)] == FULL)
			{
				cout << "SMECE\n";
			}
			else {
				p[find(a)] = FULL;
				cout << "LADICA\n";
			}
		}
		else {
			int pa = p[find(a)];
			int pb = merge(a, b);
			if (pa == FULL && pb == FULL)
			{
				cout << "SMECE\n";
			}
			else
			{
				cout << "LADICA\n";
			}
			if (pa == FULL) p[find(b)] = FULL;
		}
	}

}



