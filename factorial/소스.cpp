#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

long long n;


int main() {

	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		int idx = i;
		while (idx / 5) {
			if (!(idx % 5)) tmp++;
			else break;

			idx /= 5;
		}
		for (int j = 0; j < tmp; j++)cnt++;
	}
	printf("%d", cnt);
}