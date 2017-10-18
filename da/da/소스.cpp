#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	float n;
	float mn = 0;
	float narr[1001];
	float ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
		if (mn < narr[i]) mn = narr[i];
	}
	for (int i = 0; i < n; i++) {
		narr[i] = narr[i] * 100 / mn;
		ans += narr[i];
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << ans / n;
}