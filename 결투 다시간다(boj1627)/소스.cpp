#include <iostream>

using namespace std;

char map[3001];
int q[3001];
int t[3001];
int n;
int anslist[3001];
int cnt;
int dfs(int now, int turn) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (!q[i]) {
			flag = 1;
			int tmp[5];
			for (int j = -2; j < 3; j++) {
				tmp[j + 2] = q[i + j];
			}
			for (int j = -2; j < 3; j++) {
				q[i + j] = 1;
			}
			int res = dfs(i, !turn);
			for (int j = -2; j < 3; j++) {
				q[i + j] = tmp[j + 2];
			}
			if (turn && res == 3) {
				return 0;
			}
			else if (res == 0) {
				return 0;
			}
		}
	}
	if (flag) return 1;
	return 3;
	
}

int main() {
	cin >> n;
	scanf("%s",&map);

	for (int i = 0; i < n; i++) {
		if (map[i] == 'P') {
			for (int j = -2; j < 3; j++) {
				if(i+j >= 0 && i+j <n) q[i + j] = 1;
			}
			t[i] = -1;
		}
		else {
			int j = 1;
			while (i - j >= 0 && map[i - j] == 'P') {
				t[i]++;
				j++;
			}
			j = 1;
			while (i + j < n && map[i + j] == 'P') {
				t[i]++;
				j++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (t[i] >= 2) anslist[cnt++] = i + 1;
	}
	if (!cnt) {
		for (int i = 0; i < n; i++) {
			if (!q[i]) {
				int tmp[5];	
				for (int j = -2; j < 3; j++) {
					tmp[j + 2] = q[i + j];
				}
				for (int j = -2; j < 3; j++) {
					q[i + j] = 1;
				}
				if (dfs(i, 1)) anslist[cnt++] = i+1;
				for (int j = -2; j < 3; j++) {
					q[i + j] = tmp[j + 2];
				}
			}
		}
	}
	if (!cnt) cout << "LOSING";
	else {
		cout << "WINNING\n";
		for (int i = 0; i < cnt; i++) cout << anslist[i] << " ";
	}
}