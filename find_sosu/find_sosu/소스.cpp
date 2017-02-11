#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>


using namespace std;

int qArr[101];

int check_sosu(int N) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (qArr[i] == 2) {
			cnt++; 
			continue;
		}
		for (int j = 2; j < qArr[i]; j++) {
			if (!(qArr[i] % j)) break;
			if (j == qArr[i] - 1) cnt++;
		}
	}
	return cnt;
}


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &qArr[i+1]);

	cout << check_sosu(N);
	
}