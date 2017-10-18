#include <iostream>

using namespace std;

#define East 0
#define West 1
#define South 2
#define North 3

int n;
double parr[4];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[30][30];

double dfs(int x, int y, int depth) {
	if (depth == n) {
		return 1;
	}
	double res = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[ny][nx]) continue;
		visit[ny][nx] = 1;
		res += parr[i] * dfs(nx, ny, depth + 1);
		visit[ny][nx] = 0;
	}

	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> parr[i];
		parr[i] *= 0.01;
	}
	visit[15][15] = 1;
	printf("%.10lf",dfs(15, 15, 0));
	
}