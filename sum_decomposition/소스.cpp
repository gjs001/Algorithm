#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int mem[201][201];
int N, K;

int main() {
	cin >> N >> K;
	mem[0][0] = 1;
	for (int i = 0; i <= 200; i++) { // 0���� �����ϴ� ������ mem[0][k]�� ä���� mem[1][k]���� �ױ����ؼ� 1���� ������ ��� ���信�� mem[0][k]���� 1�� �����ϴ�.
		for (int j = i; j >= 0; j--) { //���� ���� ū �ͺ��� �۰� ������(�׷��� mem[0][0]���� �������� ���� ����)
			for (int k = 1; k <= 200; k++) {
				mem[i][k] += mem[i - j][k - 1]; //i���� k���� ���ڷ� ����� ����� 0~i���� ���ڸ� k-1���� ���ڷ� ����� ������� ���̴�.
				mem[i][k] %= 1000000000;
			}
		}
	}
	cout << mem[N][K];
}