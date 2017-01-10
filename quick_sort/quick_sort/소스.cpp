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


void quick_sort(int left, int right) {
	if (left == right) return;

	int pivot = left;
	int nl = left;
	int nr = right;
	int n = right - left ;
	while (1) {
		for (nl++; (nl < n) && sArr[nl] <= sArr[pivot]; nl++);
		for (nr--; (nr > 0) && sArr[nr] > sArr[pivot]; nr--);
		if (nl < nr) {
			swap(nl, nr);
		}
		else break;
	}

	
	swap(pivot, nr);
	quick_sort(left, nr);
	quick_sort(nl, right);

}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &sArr[i]);
	}
	quick_sort(0, N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", sArr[i]);
	}
}