#include <iostream>

using namespace std;
int n, k;
int narr[101];
int bag, sum, ans;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> narr[i];
	for (int i = 0; i < n; i++)
	{
		bag += narr[i];
		if (bag > 8) {
			sum += 8;
			bag -= 8;
		}
		else {
			sum += bag;
			bag = 0;
		}
		if (sum >= k) {
			ans = i + 1;
			break;
		}
	}
	if(ans) cout << ans;
	else cout << -1;
}