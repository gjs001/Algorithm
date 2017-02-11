#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int N;
int stair[301];
int ans[1001][2];

int cal_stair(int n, int flag) {
	if (flag > 1) {
		return 0;
	}
	if (ans[n][flag]) return ans[n][flag];
	if (n == 1) {
		return ans[n][flag] = stair[n];
	}
	if (n == 0) return 0;

	else {
		int tmp2 = cal_stair(n - 1, flag + 1);
		int tmp1 = cal_stair(n - 2, 0);

		ans[n][flag] = max(tmp1, tmp2);
		ans[n][flag] += stair[n];
		return ans[n][flag];
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}
	cout << cal_stair(N, 0);
}


