#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#define INF 987654321

using namespace std;

int sArr[10001];

void swap(int a, int b) {
	int tmp;
	tmp = sArr[a];
	sArr[a] = sArr[b];
	sArr[b] = tmp;

}


void selection_sort(int N) {
	int Min = N-1;
	for (int i = 0; i < N; i++) {
		for (int j = N -1; j > i; j--) {
			if (sArr[j] < sArr[Min]) Min = j;
		}
		if (sArr[i] > sArr[Min]) swap(i, Min);
		Min = N - 1;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &sArr[i]);
	}
	selection_sort(N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", sArr[i]);
	}
}