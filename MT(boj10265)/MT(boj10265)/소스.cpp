#include <iostream>

using namespace std;

int n, k;
int arr[1001];
int visit[1001];
int _max;

int dfs(int depth, int now) {
	if (depth > k) return 0;
	if (visit[now]) {
		if (depth > k) return 0;
		else return 1;
	}
	visit[now] = 1;
	if (!visit[arr[now]] && !dfs(depth + 1, arr[now])) {
		visit[now] = 0;
		return 0;
	}
	if (_max < depth) _max = depth;
	return 1;

}


int main() {
	cin >> n >> k;
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &arr[i]);
	}
	int ans = 0;
	for (int i = 1; i < n+1; i++) {
		dfs(1, i);
		if (k >= ans + _max) { ans += _max;}
		_max = 0;
	}
	cout << ans;

}