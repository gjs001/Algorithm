#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

vector<P> cafe;
int t, n, m, size;
vector<P> ans;

int get_dist(int x, int y, int a, int b)
{
	return abs(x - a) + abs(y - b);
}
bool check_next(int k, int cx, int cy1, int cy2, int size) {
	int ny, nx, ly;
	nx = cafe[k].first;
	ny = cafe[k].second;

	int cnt = k;
	while (cnt < size && nx == cafe[cnt].first)
	{
		ly = cafe[cnt].second;
		cnt++;
	}
	int d1 = get_dist(cx, cy1, nx, ny);
	int d2 = get_dist(cx, cy2, nx, ly);
	if (d1 < d2)
	{
		return true;
	}
	else if (d1 > d2)
	{
		return false;
	}
	else {
		return !check_next(cnt, nx, ny, ly, size);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cafe.clear();
		ans.clear();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (x == 0 && y == 0) continue;
			cafe.push_back(P(x, y));
		}
		sort(cafe.begin(), cafe.end());
		int cx = 0, cy = 0;
		int k = 0;
		int size = cafe.size();
		ans.push_back(P(0, 0));
		while (k < size)
		{
			int ny, nx, ly;
			nx = cafe[k].first;
			ny = cafe[k].second;

			int cnt = k;
			while (cnt < size && nx == cafe[cnt].first)
			{
				ly = cafe[cnt].second;
				cnt++;
			}
			int d1 = get_dist(cx, cy, nx, ny);
			int d2 = get_dist(cx, cy, nx, ly);
			if (d1 < d2 || (d1 == d2 && check_next(cnt, nx, ny, ly, size)))
			{
				for (int i = k; i < cnt; i++)
				{
					ans.push_back(P(cafe[i].first, cafe[i].second));
				}
				cx = nx;
				cy = ly;
				k = cnt;
			}
			else
			{
				for (int i = cnt - 1; i >= k; i--)
				{
					ans.push_back(P(cafe[i].first, cafe[i].second));
				}
				cx = nx;
				cy = ny;
				k = cnt;
			}
		}
		int q = 0;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int tmp;
			cin >> tmp;
			cout << ans[tmp-1].first << " " << ans[tmp-1].second << "\n";
		}
	}
}
