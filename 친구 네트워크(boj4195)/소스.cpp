#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

unordered_map<string, int> tonum;
int p[100001];
int cnt;
int t, n;

int find(int a)
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

int merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return -p[pa];
	if (p[pa] < p[pb]) swap(pa, pb);
	p[pb] += p[pa];
	p[pa] = pb;
	return -p[pb];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(p, -1, sizeof(p));
		tonum.clear();
		
		string tmp;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int num[2] = { 0, };
			for (int j = 0; j < 2; j++)
			{
				cin >> tmp;
				if (tonum.find(tmp) == tonum.end())
				{
					tonum[tmp] = ++cnt;
					num[j] = cnt;
				}
				else {
					num[j] = tonum[tmp];
				}
			}
			cout << merge(num[0], num[1]) << "\n";
		}
		
	}
}