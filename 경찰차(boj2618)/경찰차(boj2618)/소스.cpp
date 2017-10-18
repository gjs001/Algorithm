#include <iostream>
#include <algorithm>


using namespace std;
typedef pair<int, int> P;

P narr[1003];
int n, w;
int dp[1003][1003];
int route[1003][1003];
int cur;
int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int get_dist(int now, int next) {
	return abs(narr[now].first - narr[next].first) + abs(narr[now].second - narr[next].second);
}

int dfs(int car1, int car2) {
	int &ret = dp[car1][car2];
	int &ret2 = route[car1][car2];
	if (ret) return ret;
	if (car2 == w+2 || car1 == w+2) {
		return 0;
	}
	int next = max(car2, car1) + 1;
	int a = dfs(next, car2) + get_dist(car1, next);
	int b = dfs(car1, next) + get_dist(car2, next);
	if (a > b) {
		ret = b;
		ret2 = 2;
	}
	else {
		ret = a;
		ret2 = 1;
	}
	if (car1 == 1 && car2 == 2) {
		cur = ret2;
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> w;
	narr[1].first = narr[1].second = 1;
	narr[2].first = narr[2].second = n;
	for (int i = 3; i <= w+2; i++) {
		cin >> narr[i].first >> narr[i].second;
	}
	cout << dfs(1, 2) << "\n";
	int a = 1;
	int b = 2;
	for (int i = 3; i <= w + 2; i++) {
		cout << cur << "\n";
		if (cur == 2) b = i;
		else a = i;
		cur = route[a][b];
		
	}
}