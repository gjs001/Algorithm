
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

long long ans[11][1001];

long long ascending(int n, int index) {


	if (ans[index][n] > 0) return ans[index][n];

	if (index == 10) {
		for (int i = 0; i < 10; i++) {
			ans[10][n] += ascending(n, i);
		}
		ans[10][n] %= 10007;
		return ans[10][n];
	}


	for (int i = index; i < 10; i++) {
		ans[index][n] += ascending(n - 1, i);
	}
	  
		return ans[index][n] %= 10007;

}


int main() {

	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) ans[i][1] = 1;
	ans[10][1] = 10;
	cout << ascending(N,10) ;
}