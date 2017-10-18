#include <iostream>


using namespace std;



const int MAXN = 100001;

int testarray[MAXN], inputarray[MAXN];
int n;
int T, check;

int runF(int d) {
	for (int i = 0; i < n; ++i)
		testarray[i] = inputarray[i];

	int ans = 0;
	for (int i = 0; i + 1 < n; i++)
		if (testarray[i + 1] > testarray[i] + d) ans += testarray[i + 1] - (testarray[i] + d), testarray[i + 1] = testarray[i] + d;
	for (int i = n - 1; i > 0; i--)
		if (testarray[i - 1] > testarray[i] + d) ans += testarray[i - 1] - (testarray[i] + d), testarray[i - 1] = testarray[i] + d;
	check = T - ans;
	return ans <= T;
}

int main(void) {
	cin >> n >> T; // 1번째 입력 값 N과 T
	for (int i = 0; i < n; ++i)
		cin >> inputarray[i];


	int lo = 0, hi = 1000000000;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (runF(mid)) hi = mid; else
			lo = mid + 1;
	}

	runF(lo);
	for (int i = 0; i < n; ++i)
		printf("%d ", testarray[i]);
	return 0;
}
