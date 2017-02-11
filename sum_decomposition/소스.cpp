#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int mem[201][201];
int N, K;

int main() {
	cin >> N >> K;
	mem[0][0] = 1;
	for (int i = 0; i <= 200; i++) { // 0부터 시작하는 이유는 mem[0][k]를 채워서 mem[1][k]값을 쌓기위해서 1부터 시작할 경우 정답에서 mem[0][k]값인 1씩 부족하다.
		for (int j = i; j >= 0; j--) { //빼는 수는 큰 것부터 작게 가야함(그래야 mem[0][0]값을 시작으로 값이 들어간다)
			for (int k = 1; k <= 200; k++) {
				mem[i][k] += mem[i - j][k - 1]; //i개를 k개의 숫자로 만드는 방법은 0~i개의 숫자를 k-1개의 숫자로 만드는 방법들의 합이다.
				mem[i][k] %= 1000000000;
			}
		}
	}
	cout << mem[N][K];
}