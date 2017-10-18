#include<stdio.h>
#include<queue>
//#include<Windows.h>
#define INF 987654321
using namespace std;

struct _node {
	int y;
	int x;
	int depth;
	int k;
};
struct cmp {
	bool operator()(_node a, _node b) {
		return a.depth > b.depth;
	}
};
typedef _node node;

priority_queue<node, vector<node>, cmp> pq;
//queue<node> pq;
int map[202][202];
int dist[202][202][31];

int dy1[] = { 1,-1,0,0 };
int dx1[] = { 0,0,-1,1 };

int dy2[] = { 2,2,-2,-2,1,1,-1,-1 };
int dx2[] = { -1,1,-1,1,2,-2,2,-2 };

int main() {
	int K;
	scanf("%d", &K);
	int Y, X;
	scanf("%d %d", &X, &Y);

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			for (int k = 0; k <= K; k++) {
				dist[i][j][k] = INF;
			}
		}
	}

	dist[0][0][0] = 0;


	pq.push({ 0,0,0,0 });


	int res = 0;
	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		//node now = pq.front(); pq.pop();
		if (now.y == Y - 1 && now.x == X - 1) {
			res = now.depth;
			break;
			//break;
		}
		node next2, next1;

		for (int i = 0; i < 4; i++) {
			//걍 좌우상하 이동
			next1.y = now.y + dy1[i];
			next1.x = now.x + dx1[i];


			if (next1.y >= 0 && next1.y < Y && next1.x >= 0 && next1.x < X
				&& map[next1.y][next1.x] == 0
				&& dist[next1.y][next1.x][now.k] > dist[now.y][now.x][now.k] + 1) {

				dist[next1.y][next1.x][now.k] = dist[now.y][now.x][now.k] + 1;
				pq.push({ next1.y,next1.x, dist[next1.y][next1.x][now.k] ,now.k });


			}
		}



		for (int i = 0; i < 8; i++) {

			//나이트 이동경로
			next2.y = now.y + dy2[i];
			next2.x = now.x + dx2[i];
			if (next2.y >= 0 && next2.y < Y && next2.x >= 0 && next2.x < X
				&& map[next2.y][next2.x] == 0
				&& dist[next2.y][next2.x][now.k + 1] > dist[now.y][now.x][now.k] + 1
				&& now.k<K)
			{
				dist[next2.y][next2.x][now.k + 1] = dist[now.y][now.x][now.k] + 1;
				pq.push({ next2.y,next2.x,  dist[next2.y][next2.x][now.k + 1], now.k + 1 });

			}
		}
	}


	if (res != 0)
		printf("%d\n", res);
	else if (res == 0)
		printf("-1\n");
	return 0;
}