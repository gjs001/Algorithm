#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int v, e;
bool visit[101];
vector<int> graph[101];

int dfs(int now) {
	int sum = 1;
	for (auto next : graph[now]) {
		if (!visit[next]) {
			visit[next] = 1;
			sum += dfs(next);
		}
	}
	return sum;
}


int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	visit[1] = 1;
	cout << dfs(1) -1 ;
}