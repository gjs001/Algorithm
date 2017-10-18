#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, start;
int visit[101];
int map[100][100];
int path[100];
int aaa;
int dfs(int now, int depth, int time) {
	if (depth == n - 1) {
		if (time == 256) {
			aaa = time;
		}
		return time;
	}
	int ret = 2000000000;
	for (int i = 0; i < n; i++) {
		if (visit[i] || now == i) continue;
		visit[i] = 1;
		int tmp = dfs(i, depth + 1, time + map[now][i]);
		if (ret > tmp ) {
			if (tmp + time == 590 && now == 6) {
				cout << "this";
			}
			ret = tmp;
			path[depth] = i;

		}
			visit[i] = 0;
	}
	return ret + time;
}

int main() {
	cin >> t;
	while (t--) {

		cin >> n >> start;
		aaa = 99999999;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n - 1; i++) {
			int tmp;
			cin >> tmp;

			for (int j = 0; j < i + 1; j++) {
				for (int k = i + 1; k < n; k++) {
					map[j][k] += tmp;
					map[k][j] += tmp;
				}
			}


		}
		visit[start - 1] = 1;
		int ans = dfs(start - 1, 0, 0);
		cout << ans << "\n";
	}
}