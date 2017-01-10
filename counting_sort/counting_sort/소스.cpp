#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int sArr[10001];


int main() {
	int N;
	cin >> N;
	int index;
	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		sArr[index]++;
	}
	for (int i = 0; i < 10001; i++) {
	
		while (sArr[i]) {
			printf("%d\n", i);
			sArr[i]--;
		}
	}

}