#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

#define Mn 1000000007
int n, k;
//int aArr[1001][1001];
/*
int binomial(int n, int k) {
	if (aArr[n][k]) return aArr[n][k];
	if (k == 1) return aArr[n][k] = n;
	if (n == k) return 1;
	if (k == 0) return 1;
	else {
		aArr[n][k] = binomial(n - 1, k - 1) + binomial(n - 1, k);
		return aArr[n][k] %= 10007;
	}
}

*/
int pow_Mn(long long x, long long y) {
	long long ans =1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= Mn;
		}
		x *= x;
		x %= Mn;
		y /= 2;
	}
	return ans;
}
int ferma(int n, int k) {
	long long a =1;
	long long b =1;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		a *= i;
		a %= Mn;
	}
	for (int i = 1; i <= k; i++) {
		b *= i;
		b %= Mn;
	}
	for (int i = 1; i <= n - k; i++) {
		b *= i;
		b %= Mn;
	}
	b = pow_Mn(b, Mn-2);
	b %= Mn;
	ans = a*b;
	return ans %= Mn;
	
	
}
int main() {

	cin >> n >> k;
	//ans = binomial(n, k);
	long long ans = ferma(n, k);
	printf("%d", ans);
}