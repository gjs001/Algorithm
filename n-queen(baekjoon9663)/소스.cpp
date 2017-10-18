#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int n, ans;
//int visit[16];
int visit[16][16];
int di[] = { 1, 1, 1 };
int dj[] = { -1, 0, 1 };

void backt(int row) {
	for (int i = 1; i <= n; ++i) {
		if (visit[row][i])continue;

		for (int j = 0; j < 3; ++j) { // 지금 퀸 위치에서 부터 왼쪽 대각선으로 visit, 밑으로 visit, 오른쪽 대각선으로 visit 처리
			int ni = row; // 다음 열
			int nj = i; // 다음 행
			while (ni <= n&&nj >= 1 && nj <= n) {
				ni += di[j]; 
				nj += dj[j];
				visit[ni][nj]++;							
			}
		}

		if (row == n) ans++;
		else {
			backt(row + 1);
		}
		//원래대로 백트랙킹
		for (int j = 0; j < 3; ++j) {
			int ni = row;
			int nj = i;
			while (ni <= n&&nj >= 1 && nj <= n) {
				ni += di[j];
				nj += dj[j];
				visit[ni][nj]--;
			}
		}

	}
}
int main() {
	cin >> n;
	backt(1);
	//backt(-1);
	cout << ans;
}
/*
bool check(int depth) {
	for (int i = 0; i < depth; i++) {
		if (visit[i] == visit[depth] || depth - i == abs(visit[depth] - visit[i])) {
			return false;
		}
	}
	return true;
}

void backt(int depth) {
	int cnt = 0;
	if (depth == n - 1) {
		ans++;
		return;
	}
	for(int i = 0; i < n; i++) {
		visit[depth + 1] = i;
		if (check(depth + 1)) {
			backt(depth + 1);
		}
	}
}

*/
