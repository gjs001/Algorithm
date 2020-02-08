#include <iostream>

using namespace std;

long long seg[1 << 21];
long long lazy[1 << 21];
int narr[1000001];
int n,m,k;
long long init(int now, int lb, int rb) {
	if (lb == rb) return seg[now] = narr[lb];
	return seg[now] = init(now * 2, lb, (lb + rb) / 2) + init(now * 2 + 1, (lb + rb) / 2 + 1, rb);
}

void propagate(int now, int lb, int rb)
{
	if (lazy[now] != 0)
	{
		if (lb != rb)
		{
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		seg[now] += lazy[now] * (rb - lb+1);
		lazy[now] = 0;
	}
}

void add(int now, int left, int right, int lb, int rb, int data)
{
	propagate(now, lb, rb);
	if (lb > right || rb < left) return;
	if (left <= lb && rb <= right) {
		lazy[now] += data;
		propagate(now,lb,rb);
		return;
	}
	add(now * 2, left, right, lb, (rb + lb) / 2, data);
	add(now * 2 + 1, left, right, (rb + lb) / 2 + 1, rb, data);
	seg[now] = seg[now * 2] + seg[now * 2 + 1];
}


long long sum(int now, int left, int right, int lb, int rb)
{
	propagate(now, lb, rb);
	if (lb > right || rb < left) return 0;
	if (left <= lb && rb <= right) return seg[now];
	return sum(now * 2, left, right, lb, (lb + rb) / 2) + sum(now * 2 + 1, left, right, (rb + lb) / 2 + 1, rb);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> narr[i];
	init(1, 0, n - 1);
	for (int i = 0; i < m + k; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd & 1)
		{
			int s, e, d;
			cin >> s >> e >> d;
			add(1, s-1, e-1, 0, n - 1, d);
		}
		else {
			int s, e;
			cin >> s >> e;
			cout << sum(1, s-1, e-1, 0, n - 1) << "\n";
		}
	}
}