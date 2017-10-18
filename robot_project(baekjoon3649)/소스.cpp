#define _CRT_SECURE_NO_WARNINGS

#define maxn 100000000
#define cm 10000000
#include <iostream>
#include <algorithm>
using namespace std;

int lp[1000000];
int n, nx, x;
int binarysearch(int target, int idx) {
	int left = 0;
	int right = n - 1;
	int mid = (left + right) / 2;
	while (left <= right) {
		if (target > lp[mid]) {
			left = mid + 1;
		}
		else if (target == lp[mid]) {
			if (idx == mid) return 0;
			else return 1;
		}
		else {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return 0;
}

int main() {
	while (scanf("%d", &x) == 1) {
		nx = x * cm;

		cin >> n;

		for (int i = 0; i < n; i++) {
			scanf("%d", &lp[i]);
		}
		if (maxn * 2 < nx) {
			cout << "danger\n";
			continue;
		}
		sort(lp, lp + n);
		int tmp = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			tmp = binarysearch(nx - lp[i], i);
			if (tmp) {
				ans = i;
				break;
			}
		}
		if(tmp) printf("yes %d %d\n", lp[ans], nx - lp[ans]);
		else cout << "danger\n";
	}
}
