#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
int n;
P arr[51];
int ans[51];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans[arr[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}
