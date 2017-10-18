#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


char archi[52];
char list[51][52];


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", &list[i]);
	}
	int len = strlen(list[0]);
	if (N == 1) {
		cout << list[0];
		return 1;
	}
	for (int i =0; i < len; i++) {
		if (list[0][i] == list[1][i]) {
			archi[i] = list[0][i];
		}
		else
			archi[i] = '!';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < len; j++) {
			if (archi[j] == '!') continue;
			if (archi[j] != list[i][j]) archi[j] = '!';
		}
	}
	for (int i = 0; i < len; i++) {
		if (archi[i] == '!') archi[i] = '?';
	}
	cout << archi;
}
