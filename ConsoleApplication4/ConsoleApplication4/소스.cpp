#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>


//n��° ��ģ���� n��°�� �׻� 1�̰� n-2��° ��ģ���� ��+ n-3��° ��ģ��

using namespace std;

long long ans[91];
long long pinarynumber(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else if (n == 3) return 2;
	if (ans[n] > 1) return ans[n];
	for (int i = 1; i < n - 1; i++) ans[n] += pinarynumber(i);
	ans[n] += 1;
	return ans[n];
}

int main() {
	int N;
	cin >> N;
	long long ans1;
	printf("%lld",pinarynumber(N));

}