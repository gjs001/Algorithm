#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;


int N;

int sosu[5000]; // 소수인 숫자들을 저장하기 위한 배열
bool cArr[10001]; // idx에 해당하는 수가 소수이면 false 소수가 아니면 true
int tArr[10000]; // 문제의 testcase들이 모여있는 배열


int main() {

	cin >> N; // 입력부
	for (int i = 0; i < N; i++) {
		scanf("%d", &tArr[i]);
	}

	int cnt = 0;

	for (int i = 2; i <= 10000; i++) { //먼저 4~10000사이의 소수를 구해서 sosu[]에 저장한다.
		if (cArr[i] == true) continue;
		sosu[cnt++] = i;
		for (int j = i*2; j <= 10000; j += i) {
			cArr[j] = true;
		}
	}
	
	for (int i = 0; i < N; i++) { 
		int gap = 10000;
		int gidx = 0;
		for (int j = 0; j < cnt; j++) { // tArr에 저장된 testcase 값을 저장된 소수와 뺀 값을 비교
			int tmp = tArr[i] - sosu[j];
			if (cArr[tmp] == false) {//testcase - sosu[]가 소수일 경우 
				if (sosu[j] >= tmp) { // 두 소수간의 차이를 저장해 차이가 가장 적을 때의 소수값을 찾는다.

					if (gap > (sosu[j] - tmp)) { // 음수가 나오면 안되니 조건문으로 확인하고 두 경우로 나누어서 계산
						gap = sosu[j] - tmp;
						gidx = j; 
					}
				}
				else {

					if (gap > (tmp - sosu[j])) { 
						gap = tmp - sosu[j];
						gidx = j;
					}
				}
				
			}
		}
		if((tArr[i] - sosu[gidx]) > tArr[i]/2)	printf("%d %d\n",sosu[gidx],tArr[i] - sosu[gidx]); // 두 소수 중에서 항상 작은 값이 먼저 출력되어야 한다.
		else printf("%d %d\n", tArr[i] - sosu[gidx], sosu[gidx]);
	}
}