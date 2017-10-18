#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))

#define INF 987654321
int n, m;
int ans;
char graph[222][222];
bool visit[222][222];
int ox[4] = { 1 , -3, -1, -1 };
int oy[4] = { 0, 0 ,1,-1 };
int rx[4] = { -1, 3, 1,1 };
int ry[4] = { 0,0,1,-1 };

int dx[4] = { 2 ,-2,0,0 };
int dy[4] = { 0,0,1,-1 };
int dc[5] = { 0,1,2,3,4 };
int path[40002];
int c[20100][5];
int f[20100][5];

//int dist[102][202];


bool dijkstra(int sy, int sx) {
	queue<int> que;
	que.emplace(sy*2*n+sx);
	visit[sy][sx] = true;
	//dist[sy][sx] = 0;
	while (que.size()) {
		int x = que.front() % (2*n);
		int y = que.front() / (2*n);

		if (graph[y][x] == 'H') {
				ans++;
			return 1;
		}

		que.pop();
		if (!(x % 2)) {
			if ( c[2 * n*y + x][dc[4]] - f[2 * n*y + x][dc[4]] > 0){
			//dist[y][x + 1] = nd + 1;
			path[2 * n*y + x + 1] = 2 * n*y + x;
			visit[y][x + 1] = 1;
			que.emplace(2 * n*y + x + 1);
			}
			else {
				for (int i = 0; i < 4; i++) {
					int nx = x + rx[i];
					int ny = y + ry[i];

					if (nx >= 0 && nx < 2 * n && ny >= 0 && ny < m  && graph[ny][nx] != '#' && !visit[ny][nx] && c[2 * n*y + x][dc[i]] - f[2 * n*y + x][dc[i]] > 0) {
					//	dist[ny][nx] = min(dist[ny][nx], dist[y][x] + 1);
						path[2 * ny*n + nx] = 2 * n *y + x;
						que.emplace(2 * n*ny + nx);
						visit[ny][nx] = 1;
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = x + ox[i];
				int ny = y + oy[i];
				//&& dist[ny][nx] > dist[y][x]+1 
				if (nx >= 0 && nx < 2 * n && ny >= 0 && ny < m && graph[ny][nx] != '#' && c[2 * n*y + x][dc[i]] - f[2 * n*y + x][dc[i]] > 0 && !visit[ny][nx]) {
					//dist[ny][nx] = min(dist[ny][nx], dist[y][x] + 1);
					path[2 * ny*n + nx] = 2 * n*y + x;
					que.emplace(2 * n*ny + nx);
					visit[ny][nx] = 1;
				}
			}
		}

	}
	return 0;

}

int main() {
	cin >> m >> n;
	int x, y, s;
	int no = 0;
	int tx, ty,t;
	char tmp;
	for (int i = 0; i < m; i++) {
		scanf("%c", &tmp);
		for (int j = 0; j < n; j++) {
			scanf("%c", &graph[i][j*2]);
			if (graph[i][j * 2] == '.') {
				graph[i][j * 2 + 1] = '.';
			}
			if (graph[i][j * 2] == '#') {
				graph[i][j * 2 + 1] = '#';
			}
			if (graph[i][j*2] == 'K') {
				graph[i][j * 2 + 1] = '.';
				x = 2*j;
				y = i;
				s = i*n*2 + 2 * j;
			}
			if (graph[i][j*2] == 'H') {
				graph[i][j * 2 + 1] = '.';
				tx = 2*j;
				ty = i;
				t = i*n*2 + 2*j;
			}
			//dist[i][j] = INF;
		//	dist[i][j+n] = INF;
			
		}
	}
	
	for (int i = 0; i < 2*n*m; i++) {
		int x = i % (2 * n);
		int y = i / (2 * n);
		if (!(i % 2)) {
			if (i == s) c[i][dc[4]] = INF;
			else c[i][dc[4]] = 1;
		}
		else {
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < 2 * n && ny >= 0 && ny < m) {
					c[i][dc[j]] = 1;
				}
				
			}
		}

	}
	memset(path, -1, sizeof(path));

	if ( (abs(tx - x) == 2 && abs(ty-y) == 0)  ||  (abs(tx - x) == 0 && abs(ty - y) == 1) ) ans = -1;
	else while (dijkstra(y, x)) {
		


		for (int i = t; i != s; i = path[i]) {
			if (!(i % 2)) {
				if (path[i] - i == -1) {
					f[path[i]][0]++;
					f[i][1]--;
				}
				else if (path[i] - i == 3) {
					f[path[i]][1]++;
					f[i][0]--;
				}
				else if (path[i] - i == 2*n + 1) {
					f[path[i]][3]++;
					f[i][2]--;
				}
				else if (path[i] - i == -2 * n +1) {
					f[path[i]][2]++;
					f[i][3]--;
				}
				else if (path[i] - i == 1) {
					f[path[i]][4]++;
					f[i][4]--;
				}
			}
			else {
				f[path[i]][4]++;
				f[i][4]--;
			}
		}

		memset(path, -1, sizeof(path));
		memset(visit, 0, sizeof(visit));
		
	}
	cout << ans<<endl;
}