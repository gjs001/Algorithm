#include <iostream>
#include <algorithm>

using namespace std;

int seg[1 << 20];
int lazy[1 << 20];
int narr[500001];
int n,m;

int init(int now, int lb = 0, int rb = n - 1)
{
	if (lb == rb) return seg[now] = narr[lb];
	return seg[now] = init(now * 2, lb, (lb + rb) / 2) ^ init(now * 2 + 1, (lb + rb) / 2 + 1, rb);
}

void propagate(int now, int lb , int rb)
{
	if (lazy[now] != 0)
	{
		if (lb != rb)
		{
			lazy[now * 2] ^= lazy[now];
			lazy[now * 2 + 1] ^= lazy[now];
		}
		if((rb-lb+1) & 1) seg[now] ^= lazy[now];
		lazy[now] = 0;
	}
}


void update(int now, int left, int right, int data, int lb = 0, int rb = n - 1)
{
	propagate(now, lb, rb);
	if (rb < left || lb > right) return;
	if (left <= lb && rb <= right) {
		lazy[now] ^= data;
		propagate(now,lb,rb);
		return;
	}
	update(now * 2, left, right, data, lb, (lb + rb) / 2);
	update(now * 2 + 1, left, right, data, (lb + rb) / 2 + 1, rb);
	seg[now] = seg[now * 2] ^ seg[now * 2 + 1];
}

int getseg(int now, int left, int right, int lb = 0, int rb = n - 1)
{
	propagate(now, lb, rb);
	if (rb < left || lb > right) return 0;
	if (left <= lb && rb <= right) return seg[now];
	return getseg(now * 2, left, right, lb, (lb + rb) / 2) ^ getseg(now * 2 + 1, left, right, (lb + rb) / 2+1, rb);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> narr[i];
	init(1);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd & 1)
		{
			int s, e, d;
			cin >> s >> e >> d;
			if (s > e) swap(s, e);
			update(1, s, e, d);
		}
		else {
			int s, e;
			cin >> s >> e;
			if (s > e) swap(s, e);
			cout << getseg(1, s, e) << "\n";
		}
	}

}