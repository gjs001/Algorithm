#include <iostream>

using namespace std;

int n, k;
int karr[101];
int seat[8];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> karr[i];
	}
	int ans = 1;
	int now = 0;
	int row = 0;
	int side = 0;
	for (int i = 0; i < k; i++) {
		now += karr[i];
		if (karr[i] & 1) {
			++now;
			++row;
		}
	}
	if ((now>8 * n) || ((now == 8 * n) && (k == 4 * n) && (row<n))) cout << "NO";
	else cout << "YES";
}