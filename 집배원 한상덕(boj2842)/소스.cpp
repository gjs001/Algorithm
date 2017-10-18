#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int abs(int a) {
	if (a < 0) return -a;
	else return a;
}

int n;
int k;
int dx[8] = { 0,1,1,1,0,-1 ,-1 ,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int visit[51][51];
char map[51][51];
int height[51][51];
int harr[2501];
int cnt;
P start;
queue<P> que;

bool bfs(int left, int right) {
	if (height[start.first][start.second] < left || height[start.first][start.second] > right) return false;
	memset(visit, 0, sizeof(visit));
	que.push(P(start));
	int cnt = 0;
	visit[start.first][start.second] = 1;
	while (!que.empty()) {
		P now = que.front();
		que.pop();
		if (map[now.first][now.second] == 'K') {
			cnt++;
		}
		for (int i = 0; i < 8; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
			if (height[ny][nx] < left || height[ny][nx] > right) continue;
			visit[ny][nx] = 1;
			que.push(P(ny, nx));

		}

	}
	if (cnt == k) return true;
	else return false;

}

void dfs(int left, int right, int y, int x) {

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
		if (height[ny][nx] < left || height[ny][nx] > right) continue;
		visit[ny][nx] = 1;
		dfs(left, right, ny, nx);
	}
}

bool init(int left, int right) {
	memset(visit, 0, sizeof(visit));
	visit[start.first][start.second] = 1;
	if (height[start.first][start.second] < left || height[start.first][start.second] > right) return false;
	else dfs(left, right, start.first, start.second);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'K' && !visit[i][j]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'K') {
				k++;
			}
			if (map[i][j] == 'P') {
				start.first = i;
				start.second = j;
			}
		}
	}
	int hcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			harr[hcnt++] =height[i][j];
		}
	}
	
	sort(harr, harr + hcnt);
	hcnt = unique(harr, harr + hcnt) - harr;
	
	int k_max_height = 0;
	int k_min_height = 1000001;
	int left = 0;
	int right = 0;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'K' && k_max_height < height[i][j]) {
				k_max_height = height[i][j];
			}
			if (map[i][j] == 'K' && k_min_height > height[i][j]) {
				k_min_height = height[i][j];
			}
		}
	}

	for (int i = 0; i < hcnt; i++) {
		if (k_max_height == harr[i]) right = i;
	}
	right = 0;
	left = 0;
	int ret = 1000001;
	while (harr[left] <= k_min_height && right < hcnt ) {
		bool flag = bfs(harr[left], harr[right]);
	
		if (!flag) {
			int nr1 = right+1;
			int nr2 = hcnt - 1;
			while (nr1 < nr2) {
				int mid = (nr1 + nr2) / 2;
				if (bfs(harr[left], harr[mid])) nr2 = mid;
				else nr1 = mid + 1;
			}
			right = nr1;
		}
		else {
			int nl1 = left;
			int nl2 = right;
			while (nl1 < nl2 - 1) {
				int mid = (nl1 + nl2) / 2;
				if (bfs(harr[mid], harr[right])) nl1 = mid;
				else nl2 = mid;
			}
			left = nl1;
			if (ret > harr[right] - harr[left]) ret = harr[right] - harr[left];
			left++;
		}
		
	}

	cout << ret;
}