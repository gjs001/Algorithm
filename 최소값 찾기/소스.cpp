#include <iostream>
#include <algorithm>
using namespace std;

int seg[1 << 24];
int n, bn, l;
void init()
{
	//fill_n(seg, 1 << 24, 1000000321);
	seg[bn + n] = 1000000321;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

		int cur = bn + i;
		seg[cur] = a;

	}
	for (int i = bn - 1; i >= 1; i--)
	{
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
}
int get_min(int cur, int left, int right, int lb, int rb)
{
	if (rb < left || right < lb) return 1000000321;
	if (left <= lb && rb <= right)
		return seg[cur];
	int mid = (lb + rb) / 2;
	return min(get_min(cur * 2, left, right, lb, mid), get_min(cur * 2 + 1, left, right, mid + 1, rb));
}
void func()
{
	for (int right = 0,left = (right-l+1); right < n; right++,left++)
	{
		cout << get_min(1, (left >= 0 ? left : 0), right, 0, bn - 1) << " ";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bn = 1 << 23;
	cin >> n >> l;
	init();
	func();
}