#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> v[101];
#define INF 987654321

int dp[101][21];

int Min(int a, int b) {
	if (a > b) return b;
	return a;
}

int Abs(int a) {
	if (a < 0) return (-a);
	return a;
}
int dfs(int h, int d) {
	if (d == n) {
		return 0;
	}
	int& ret = dp[d][h];
	if (ret != INF)
		return ret;


	for (int i = 0; i<v[d].size(); i++) {
		if (Abs(h - v[d][i]) <= 1 || h * 2 == v[d][i] || (h * 2 >= 20 && v[d][i] == 20)) {
				ret = Min(ret, dfs(v[d][i], d + 1));
		}
		else {
			ret = Min(ret, dfs(v[d][i], d + 1)+1);
		}
	}

	return ret;

}


int main() {

	cin >> n >> k;
	for (int i = 0; i<n; i++) {
		int m, num;
		scanf("%d", &m);
		for (int j = 0; j<m; j++) {
			scanf("%d", &num);
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			dp[i][j] = INF;
		}
	}
	int a = dfs(1, 0);
	if (a <= k)
		cout << a;
	else
		cout << -1;

}