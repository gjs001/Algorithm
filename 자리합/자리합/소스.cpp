#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
using namespace std;

long long cnt[10];
int t, idx;
long long a, b;
long long deca[16];
long long ans[2];

void cal(long long tar) {
	long long d = tar;
	for (int i = 15; i >= 0; i--) {
		int now = d / deca[i];
		if (now == 0) continue;
		
		int t = 1;
		while (t < now) {
			cnt[t] += deca[i];
			t++;
		}
		if (t == now) {
			d -= (now*deca[i]);
			cnt[t] += d+1;
		}
		for (int j = 1; j < 10; j++) {
			if (i - 1 < 0) break;
			cnt[j] += deca[i-1] * i * now;
		}
	}
	for (int i = 1; i < 10; i++) {
		ans[idx] += cnt[i] * (i);
	}
	idx++;
}
int main() {
	scanf("%d", &t);
	deca[0] = 1;
	for (int i = 1; i < 16; i++) deca[i] = deca[i - 1] * 10;
	while (t--) {
		idx = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		scanf("%lld %lld",&a,&b);

		cal(b);
		memset(cnt, 0, sizeof(cnt));
		cal(a-1);
		

		printf("%lld\n", ans[0] - ans[1]);

	}
}

