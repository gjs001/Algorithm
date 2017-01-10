#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int ansfield[10001];

using namespace std;

int N;
int maxcheck(int ans1, int ans2, int ans3) {
	if (ans1 > ans2) {
		if (ans1 > ans3) return ans1;
		else return ans3;
	}
	else {
		if (ans2 > ans3) return ans2;
		else return ans3;
	}
}
int vinovino(int n, int *test) {
	if (n == 0) return 0;
	else if(n == 1){
		return test[1];
	}
	else if(n == 2){
		return test[1] + test[2];
	}
	
	if (ansfield[n] > 0) {
		return ansfield[n];
	}

	
		//1번경우 n번째를 안마셨을 때 n-1이최대치 2번의 경우 n번째를 연속해서 첫잔으로 마셨을 때 3번의 경우 n번째를 연속해서 두번째잔으로 마셨을 때
		ansfield[n] = maxcheck(vinovino(n - 1, test), vinovino(n - 2, test) + test[n], vinovino(n - 3, test) + test[n] + test[n-1]);
		return ansfield[n];

 }


int main() {
	
	cin >> N;
	int test[10001];
	for (int i = 1; i < N+1; i++)
		scanf("%d", &test[i]);
	cout << vinovino(N,test);


}