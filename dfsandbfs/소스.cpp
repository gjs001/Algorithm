#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int graph[1001][1001];
bool visit[1001];
int N, M, start;
int cnt;
bool flag;
int ansD[1001];
int ansB[1001];

void dfs() {
	stack<int> A;
	char tmp[2];
	A.push(start);
	int cntd = 0;
	ansD[cntd++] = start;
	
	 int popcnt = 0;
	visit[start] = true;
	while (!A.empty()) {
		int cur = A.top();
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] && !visit[i]) {
				A.push(i);
				ansD[cntd++] = i;
				visit[i] = true;
				break;
			}
			else if (i == N) flag = true;

		}
		if (flag) {
			A.pop();
			flag = false;
			popcnt++;
		}
	}

}
void bfs() {
	queue<int> A;
	char tmp[2];
	A.push(start);
	visit[start] = true;

	int cntb = 0;
	ansB[cntb++] = start;
	int popcnt = 0;
	while (!A.empty()) {
		int cur = A.front();
		A.pop();
		popcnt++;
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] && !visit[i]) {
				A.push(i);

				visit[i] = true;
				ansB[cntb++] = i;
			}
		}
	}

}
int main() {
	cin >> N >> M >> start;
	int v1, v2;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	dfs();
	for (int i = 0; i < N; i++) {
		cout << ansD[i] << ' ';
	}

	memset(visit, false, sizeof(bool)* (N+1));
	bfs();
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << ansB[i] << ' ';
	}
}