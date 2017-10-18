#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int a, b, c;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	if (b - a > c - b) {
		cout << b - a - 1;
	}
	else cout << c - b - 1;
}