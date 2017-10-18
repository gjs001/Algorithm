#include <iostream>
#include <algorithm>
using namespace std;

int seg[19][1<<17];
int n, m;
int bn,md;
int narr[100001];

void set_seg(int depth, int left, int right)
{
	if (depth == md) 
	{
		seg[depth][left] = narr[left];
		return;
	}
	int mid = (left + right) / 2;
	set_seg(depth + 1, left, mid);
	if(mid+1 <= right)set_seg(depth + 1, mid + 1, right);
	int now_idx = left;
	int left_idx = left;
	int right_idx = mid + 1;
	while (now_idx <= right)
	{
		if (left_idx < mid + 1 && (seg[depth + 1][left_idx] < seg[depth + 1][right_idx] || right_idx > right) )
		{
			seg[depth][now_idx++] = seg[depth + 1][left_idx++];
		}
		else
		{
			seg[depth][now_idx++] = seg[depth + 1][right_idx++];
		}
	}
}

int check(int refv, int depth, int left, int right, int lb, int rb)
{
	int res;
	if (depth > md) 
		return 0;
	if (left > rb || right < lb) return 0;
	if (left <= lb && rb <= right)
	{
		res = (lower_bound((seg[depth]) + lb, (seg[depth]) + rb + 1, refv) - (seg[depth] + lb));
		return res;
	}
	int mid = (lb + rb) / 2;
	return check(refv, depth + 1, left, right, lb, mid) + check(refv, depth + 1, left, right, mid + 1, rb);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> narr[i];

	bn = 1;
	while (bn < n)
	{
		bn <<= 1;
		md++;
	}
	set_seg(0, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int arr_left, arr_right, number;
		cin >> arr_left >> arr_right >> number;
		int left = -1000000000;
		int right = 1000000000;
		int res = 0;
		while (left < right)
		{
			int mid = (left + right+1) / 2;
			if ((res = check(mid, 0, arr_left - 1, arr_right - 1, 0, n-1)) >= number) right = mid - 1;
			else left = mid;
		}
		cout << left << "\n";
	}
}