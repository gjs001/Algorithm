#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int n, k;
long long ans[10000];
#define min(a,b) ((a)<(b)?(a):(b))

long long binomial(int n, int r) {
	r = min(r, n - r);
	long long ans = 1;
	for (int i = 1; i <= r; ++i)
		ans = ans*(n + 1 - i) / i;

	return ans;
}



int main() {
	int cnt = 0;
	
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		ans[cnt++] = binomial(n, k);

	}
	for (int i = 0; i < cnt; i++) {
		printf("%lld\n", ans[i]);
	}
}