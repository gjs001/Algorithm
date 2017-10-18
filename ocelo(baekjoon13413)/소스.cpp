#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>
using namespace std;

int T, N;
char init[100002];
char last[100002];

int main() {
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N;
		scanf("%s", &init);
		scanf("%s", &last);
		int white = 0;
		int black = 0;
		for (int i = 0; i < N; i++) {
			if (init[i] == last[i]) continue;
			else {
				if (init[i] == 'B') black++;
				else white++;
			}
		}
		ans = white > black ? white : black;
		printf("%d\n", ans);
	}
}