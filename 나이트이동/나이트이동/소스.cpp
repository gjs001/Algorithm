#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;


typedef struct point {
	int y;
	int x;
	int d;
}point;

int visit[301][301];
int n, t;
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };

queue<point> que;

int main() {
	
	scanf("%d",&t);
	while (t--) {
		memset(visit, 0, sizeof(visit));
		while (que.size())que.pop();
		scanf("%d",&n);
		int a, b, c, d;
		point start;
		point target;
		scanf("%d %d",&a, &b);
		scanf("%d %d", &c, &d);
		start.y = a;
		start.x = b;
		start.d = 0;
		que.push(start);
		visit[start.y][start.x] = 1;
		while (que.size()) {
			point now = que.front();
			que.pop();
			if (now.y == c && now.x == d) {
				printf("%d\n", now.d);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
				visit[ny][nx] = 1;
				point np;
				np.y = ny;
				np.x = nx;
				np.d = now.d + 1;
				que.push(np);
			}
		}

	}
}