#include <iostream>

using namespace std;

int dp[100001];

int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		while (tmp--) {
			dp[cur++] = i;
		}
	}
	for (int i = 0; i < q; i++) {
		int tmp;
		cin >> tmp;
		cout << dp[tmp] << "\n";
	}
}