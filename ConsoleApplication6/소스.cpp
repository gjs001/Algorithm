#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

char t1[1002];
char t2[1002];
int graph[1002][1002];

int search(int n, int m) {
	int curx = m - 1;
	int cury = n - 1;
	int ans = 0;
	while (curx >= 0 && cury >= 0) {
		int now = graph[cury][curx];
		if (now == -1) {
			cury = cury - 1;
			continue;
		}
		if (now == 0) {
			ans++;
			curx = curx - 1;
			cury = cury - 1;
			continue;
		}
		if (cury == 0 || graph[cury - 1][curx] == -1) {
			curx = curx - 1;
		}
		else if (curx == 0) {
			cury = cury - 1;
		}
		else if (graph[cury][curx-1] < graph[cury - 1][curx]) {
			curx = curx - 1;
		}
		else if (graph[cury-1][curx] == graph[cury][curx - 1]) {
			if (now < graph[cury][curx - 1]) cury = cury - 1;
			else if (now == graph[cury][curx - 1] && graph[cury-1][curx] < graph[cury-1][curx -1]) curx = curx - 1;
			else cury = cury - 1;
		}
		else {
			cury = cury - 1;
		}
	}
	return ans;
}

int main() {
	cin >> t2 >> t1;
	int n = strlen(t2);
	int m = strlen(t1);
	for (int i = 0; i < n; i++) {
		int tmp = -1;
		int cnt = -1;
		for (int j = 0; j < m; j++) {
			if (t1[i] == t2[j] && tmp == -1) {
				tmp = j;
				cnt = j;
			}
			else if (t1[i] == t2[j]) {
				cnt = j;
			}
			if (cnt != -1) {
				graph[i][j] = j - cnt;
			}
			if (tmp == -1) {
				graph[i][j] = -1;
			}
		}
		if (tmp != -1) {
			for (int j = 0; j < tmp; j++) {
				graph[i][j] = cnt - j;
			}
		}
	}
	int a = search(n,m);
	cout << a;



}
