#include <iostream>

using namespace std;

int t, n;
int narr[100001];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
	
		cin >> n;
		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			cin >> narr[k];
		}
		
		int ans = 0;
		int cmp = n + 1;
		for (int i = 1; i <= n; i++) {
			if (narr[i] < cmp) {
				cmp = narr[i];
				ans++;
			}
		}


		printf("%d\n", ans);
	}

}