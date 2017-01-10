#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int sArr[10001];

void swap(int a, int b) {
	int tmp;
	tmp = sArr[a];
	sArr[a] = sArr[b];
	sArr[b] = tmp;
}

void bubble_sort(int N) {
   
	for (int i = N; i > 1 ; i--) {
		for (int j = 1 ; j < i; j++) {
			if (sArr[j] > sArr[j + 1]) swap(j, j + 1);
		}
	}
}


int main() {
	int N;
	cin >> N;
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &sArr[i]);
	}
	bubble_sort(N);
	for (int i = 1; i < N+1; i++) printf("%d\n", sArr[i]);
}