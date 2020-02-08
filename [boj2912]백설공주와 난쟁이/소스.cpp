#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<int, int> pii;
int ori[300001];
pii arr[300001];
int cnt[300001];
int n, c;


int binary(int c, int tar)
{
	int s = cnt[c];
	int e = cnt[c+1];
	while (s < e)
	{
		int mid = (s + e) / 2;
		if (arr[mid].second > tar) e = mid;
		else s = mid + 1;
	}
	return s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> ori[i];
		arr[i].first = ori[i];
		arr[i].second = i;
	}

	sort(arr+1, arr + n+1);
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		while (arr[i].first > idx) cnt[++idx] = i;
	}
	cnt[c + 1] = n + 1;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		int gap = e - s + 1;
		int answer = 0;
		for (int t = 100; t; t--)
		{
			if (gap == 1) {
				answer = ori[e];
				break;
			}
			int num = ori[s + (rand()%100)*gap/100];
			int res = binary(num, e) - binary(num, s-1);
			if (res * 2 > gap) {
				answer = num;
				break;
			}
			
		}
		if (answer > 0) cout << "yes " << answer;
		else cout << "no";
		cout << "\n";
	}
	

}