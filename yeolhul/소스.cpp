#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int gArr[1001][1001];
int A[1001];
int B[1001];
int N, M;
bool visit[1001];
bool dfs(int now) {
	visit[now] = true;
	for (int i = 1; i <= gArr[now][0]; i++) {
		if (B[gArr[now][i]] == 0 || !visit[B[gArr[now][i]]] && dfs(B[gArr[now][i]])) {
			A[now] = gArr[now][i];
			B[gArr[now][i]] = now;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &gArr[i][0]);
		for (int j = 1; j <= gArr[i][0]; j++) {
			int tmp;
			scanf("%d", &tmp);
			gArr[i][j] = tmp;

		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 0) {
			memset(visit, 0, sizeof(visit));
			if (dfs(i)) cnt++;
		}
	}
	cout << cnt;
	
}