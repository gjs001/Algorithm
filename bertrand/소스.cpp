#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int M, N;
bool fArr[1000001]; // idx 값에 해당하는 수가 소수이면 false 아니면 true


int main() {
	vector<int> a; // 얼마나 입력이 될지 문제에 명시되어있지 않아서 벡터를 활용

	while (1) { // 0이 나올 때 까지 계속 입력을 받는다.
		int tmp = 0;
		scanf("%d", &tmp);
		if (tmp == 0) break;
		else a.push_back(tmp);
	}
		
		
	for (int k = 0; k < a.size(); k++) { // 에라토스테네스의 체구현
		int cnt = 0;
		for (int i = 2; i <= a[k]*2; i++) { //베르트랑 공준은 n보다 크고 2*n보다 작은 값을 구하는 문제이므로 range의 맥시멈은 2*n
			if (fArr[i] == true) continue;
			if (i > a[k]) cnt++; // 미니멈은 n;
			for (int j = i * 2; j <= a[k]*2; j += i) { //체로 걸러내자
				fArr[j] = true;
			}

		}
		for (int i = 0; i < a[k] * 2; i++) fArr[i] = false; //여러번 구해야하니 fArr[] 초기화를 해주자
		printf("%d\n", cnt); //구간의 소수 갯수를 출력
	}

}