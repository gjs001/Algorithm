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


void insertion_sort(int N) {

	for (int i = 1; i < N; i++) {
	
		for (int j = i; j > 0; j--) {

			if (sArr[j] < sArr[j - 1]) swap(j, j - 1);
		}
		
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &sArr[i]);
	}
	insertion_sort(N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", sArr[i]);
	}
}