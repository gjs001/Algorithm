#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct matrix {
	long long f[2][2];
};

matrix multy(matrix A, matrix B) {
	matrix ans;
	ans.f[0][0] = (A.f[0][0] * B.f[0][0] + A.f[0][1] * B.f[1][0]) % 1000000;
	ans.f[1][0] = (A.f[1][0] * B.f[0][0] + A.f[1][1] * B.f[1][0]) % 1000000;
	ans.f[0][1] = (A.f[0][0] * B.f[0][1] + A.f[0][1] * B.f[1][1]) % 1000000;
	ans.f[1][1] = (A.f[1][0] * B.f[0][1] + A.f[1][1] * B.f[1][1]) % 1000000;

	return ans;
}

matrix fivo(matrix A, long long n) {
	matrix ans = A;
	if (n > 1) {
		ans = fivo(ans, n / 2);
		ans = multy(ans, ans);
		if (n % 2) {
			ans = multy(ans, A);
		}

	}
	return ans;

}
int main() {
	long long n;
	cin >> n;
	matrix A = { 1,1,1,0 };
	matrix Fn = fivo(A, n);
	if (n == 0) cout << 0;
	else cout << Fn.f[0][1];
}
