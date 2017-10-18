#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int narr[1001];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> narr[i];
	int now = k;
	int next = 0;
	bool flag = 1;
	sort(narr, narr + n);
	int ans = 0;
	while (flag) {
		flag = 0;
		for (int i = 0; i < n; i++) {
			if (now < narr[i]) {
				flag = 1;
				next = narr[i];
				break;
			}
		}
		int cnt = 0;
		while (now < next) {
			now *= 2;
			cnt++;
		}
		if(cnt > 0) ans += cnt - 1;
		for (int i = 0; i < n; i++) {
			if (now < narr[i]) {
				now = narr[i-1];
				break;
			}
		}		
	}

	cout << ans;

}