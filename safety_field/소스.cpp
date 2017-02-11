#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <cstring>



using namespace std;
int graph[101][101];
bool wet[101][101];
int n,cnt;
queue<pair<int,int>> que;

int bfs(int k,int start){
	int sy = (start / n) + 1;
	int sx = (start%n) + 1;

	que.push(make_pair(sy,sx));
	wet[sy][sx] = true;
	int cnt = 0;
	while (que.size()) {
		cnt++;
		int x = que.front().second;
		int y = que.front().first;
		que.pop();


		if (x - 1 > 0 && !wet[y][x - 1]) {
			que.push(make_pair(y, x - 1));
			wet[y][x - 1] = true;
		}
		if (x + 1 <= n && !wet[y][x + 1]){
			que.push(make_pair(y, x + 1));
			wet[y][x + 1] = true;
		}
		if (y - 1 > 0 && !wet[y - 1][x]){
			que.push(make_pair(y - 1, x));
			wet[y-1][x] = true;
		}
		if (y + 1 <= n && !wet[y + 1][x]){
			que.push(make_pair(y + 1, x));
			wet[y + 1][x] = true;
		}

	}
	return cnt;


}

int wetcheck(int k){
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] <= k) {
				wet[i][j] = true;
				cnt++;
			}
		}
	}
	while (cnt < n*n) {
		int start;
		for (int i = 0; i < n*n; i++) {
			if (wet[(i / n) + 1][(i%n) + 1] == false) {
				start = i;
				break;
			}
		}
		cnt += bfs(k, start);
		ans++;
	}
	return ans;
}


int main() {
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
			if (max < graph[i][j]) max = graph[i][j];
		}
	}
	int ans = 0;
	for (int k = 0; k <= max; k++) {
		int tmp = wetcheck(k);
		if (ans < tmp) ans = tmp;

		memset(wet, false, sizeof(wet));
	}
	cout << ans;
}