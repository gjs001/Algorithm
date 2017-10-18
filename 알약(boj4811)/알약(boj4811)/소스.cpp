#include <cstdio>

using namespace std;

long long dp[31];

int main() {
	int t;
	dp[0] = 1;
	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j < i; j++) {
			int k = i - j - 1;
			dp[i] += dp[j] * dp[k];
		}
	}
	while (1) {
		scanf("%d", &t);
		if (t == 0) return 1;
		printf("%lld\n", dp[t]);
	}
}