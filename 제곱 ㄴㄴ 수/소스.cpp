#include <iostream>
#include <math.h>
using namespace std;

int sosu[100000];
int scnt;
bool visit[1300001];
bool visit2[4000001];
long long _min, _max;
long long ans= 0;
int main() {

	for (int i = 2; i <= 1200000; i++) {
		if (visit[i])continue;
		sosu[scnt++] = i;
		for (int j = i; j <= 1200000; j += i) {
			visit[j] = 1;
		}
	}
	cin >> _min >> _max;
	long long base = sqrt(_min);
	int idx = 0;
	for (int i = scnt-1; i >= 0; i--) {
		long long tmp = sosu[i];
		tmp *= tmp;
		if (tmp <= _max) {
			base = sosu[i]; 
			idx = i;
			break;
		}
	}
	ans = 0;
	base *= base;
	while (1) { 
		long long start = _min / base;
		start*=base;
		for (long long i = start; i <= _max; i += base) {
			if (_min <= i && !visit2[i - _min]) {
				visit2[i - _min] = 1;
				ans++;
			}
		}
		if (idx == 0)break;
		base = sosu[--idx];
		base *= base;
	}
	ans = _max - _min - ans + 1;
	printf("%lld", ans);
}