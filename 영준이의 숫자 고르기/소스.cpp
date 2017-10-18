#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, t, bn;
vector<vector<int > > s;
vector<pair<int, int> > updatelist;

#define MOD 1000000007
long long seg[1 << 18];

long long seg_get(int cur, int left, int lb, int rb)
{
	if (left > rb || 100000 < lb) return 0;
	if (left <= lb && rb <= 100000) return seg[cur];
	int mid = (lb + rb) / 2;
	return (seg_get(cur * 2, left, lb, mid) + seg_get(cur * 2 + 1, left, mid + 1, rb));
}
void seg_renew(int idx)
{
	int data = (seg_get(1, idx, 0, (1 << 17) - 1)%MOD+1);
	updatelist.push_back(make_pair(idx,data));
}
void seg_update()
{
	int size = updatelist.size();

	for (int i = 0; i < size; i++)
	{
		int idx = updatelist[i].first;
		int data = updatelist[i].second;
		seg[bn + idx] += data;
		seg[bn + idx] %= MOD;
		int cur = (bn + idx) / 2;
		while (cur)
		{
			seg[cur] += data;
			seg[cur] %= MOD;
			cur /= 2;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input3.txt", "r", stdin);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n;
		s.clear();
		s.resize(n + 1);
		memset(seg, 0, sizeof(seg));
		
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			int tmp;
			for (int j = 0; j < m; j++)
			{
				cin >> tmp;
				s[i].push_back(tmp);
			}
			sort(s[i].begin(), s[i].end());
		}
		bn = 1 << 17;
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			updatelist.clear();
			int size = s[i].size();
			for (int j = 0; j < size; j++)
			{
				
				seg_renew(s[i][j]);

			}
			seg_update();
		}
		ans = seg_get(1, 1, 0, bn-1)%MOD + 1;
		cout << "#" << testcase << " " << ans << "\n";
	}
}
