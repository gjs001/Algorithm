#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

#define lli long long
lli ans;
int n;
lli k;

void cal(int n, lli k) {
	if (n == 1) {
		ans = (k) * 8;
		return;
	}
	else if (n == 2) {
		ans = (k/2) * 8 + 1 + (k%2) *6;
		return;
	}
	else if (n == 3) {
		ans = (k / 2) * 8 + 2 + (k % 2) * 4;
		return;
	}
	else if (n == 4) {
		ans = (k / 2) * 8 + 3 + (k % 2) * 2;
		return;
	}
	else if (n == 5) {
		ans = (k) * 8 + 4;
		return;
	}
}

int main(){
	cin >> n >> k;
	cal(n, k);
	printf("%lld", ans);

}