#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int N;
typedef struct printQ {
	int nes;
	int raw;
};

int ansarr[101];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int M;
		int targetraw;
		int targetnes;
		int ans = 0;
		cin >> M >> targetraw;
		printQ *arr = new printQ[M];
		printQ tmp;
		int *nesarr = new int[M];
		int cur = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &nesarr[j]);
			arr[j].raw = j;
			arr[j].nes = nesarr[j];

		}
		targetnes = nesarr[targetraw];
		sort(nesarr, nesarr + M, greater<int>());
		int cnt = 0;
		while (1) {

			if (arr[cur].nes == nesarr[cnt] && targetraw == arr[cur].raw) {
				ans++;
				break;
			}
			else if (arr[cur].nes == nesarr[cnt]) {
				ans++;
				cnt++;
				cur++;
				if (cur == M) cur = 0;
			}
			else{
				cur++;
				if (cur == M) cur = 0;
			}


		}

		ansarr[i] = ans;
		delete[] nesarr;
		delete[] arr;
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d\n", ansarr[i]);
	}
}
