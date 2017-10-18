#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long a[100001],b[100001],c[100001],p[100001],d[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i < m; i++)
	{
		int prev = p[i];
		int next = p[i + 1];
		if (prev > next) swap(prev, next);
		d[prev]++; d[next]--;
	}
	for (int i = 1; i < n; i++)	cin >> a[i] >> b[i] >> c[i];
	long long ans = 0; long long w = 0;
	for (int i = 1; i < n; i++)
	{
		w += d[i];
		ans += min(a[i] * w, b[i] * w + c[i]);
	}
	cout << ans;
}
