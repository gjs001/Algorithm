#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int sArr[10000];

void swap(int a, int b) {
	int tmp;
	tmp = sArr[a];
	sArr[a] = sArr[b];
	sArr[b] = tmp;
}


void sequential_sort(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sArr[i] > sArr[j])
				swap(i, j);
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &sArr[i]);
	}
	sequential_sort(N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", sArr[i]);
	}

}