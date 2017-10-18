#include <cstdio>
#include <queue>

using namespace std;

#define INF 987654321
#define min(a,b) (a < b ? a : b)

int f, s, g, u, d;
int visit[1000001];

bool bfs(int start) {
	queue<int> que;

	que.push(start);
	visit[start] = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (cur == g) {
			printf("%d", visit[cur]);
			return 1;
		}
		if (u && cur + u <= f && !visit[cur + u]) {
			que.push(cur + u);
			visit[cur + u] = visit[cur] + 1;
		}
		if (d && cur - d >= 0 && !visit[cur - d]) {
			que.push(cur - d);
			visit[cur - d] = visit[cur] + 1;
		}
	}
	return 0;
}



int main() {

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	if (s == g) printf("0");
	else if (bfs(s) == 0) printf("use the stairs");

}