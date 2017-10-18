#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;
int n;
P narr[100002];
bool bound[100002];
long long ans;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> narr[i].first;
		narr[i].second = i;
	}
	bound[0] = bound[n + 1] = 1;
	sort(narr + 1, narr + n + 1);
	for (int i = 1; i <= n; i++) {
		long long length = 0;
		int cnt = 0;
		long long sum = 0;
		while (!bound[narr[i].second + cnt]) {
			cnt++;
		}
        length += cnt;
		cnt = 0;
		while (!bound[narr[i].second - cnt -1]) {
			cnt++;
		}
        length += cnt;
		bound[narr[i].second] = 1;
		sum = length * narr[i].first;
		if (ans < sum) ans = sum;
	}
	cout << ans;
}