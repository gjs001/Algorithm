#include <iostream>

using namespace std;

int n, s, cnt;
int narr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (s > tmp) narr[cnt++] = tmp;
	}
	for (int i = 0; i < cnt; i++) {
		cout << narr[i] << " ";
	}
}