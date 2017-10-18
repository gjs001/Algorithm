#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

#define pii pair<int, int>

int n, q;
long long list[2000001];
long long qarr[2000001][3];
long long test[1000001][2];
int main() {

	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d",&tmp);
		list[i] = tmp;

	}
	/*
	for (int i = 1; i <= 1000000; i++) {
		list[i] = 1000000;
		test[i][0] = 1;
		test[i][1] = 1000000;
	}*/
	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		qarr[a][0] += 1;
		qarr[a + b][1]+= -b;
		qarr[a + b][2] += 1;
	}
	long long add = 0;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (qarr[i][0]) { cnt += qarr[i][0]; }
		if (qarr[i][2]) {	
			cnt -= qarr[i][2];
			add += qarr[i][1];
		}
		add += cnt;
		list[i] += add;
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", list[i]);
	}
	
}