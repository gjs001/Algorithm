#include <iostream>
#include <stdio.h>
#include <queue>
#include <fstream>
#define MAXN 30

using namespace std;


int fx[8] = { -2,-1,+1,+2,+2,+1,-1,-2 };
int fy[8] = { -1,-2,-2,-1,+1,+2,+2,+1 };
int m, n, sx, sy, ex, ey;
int _data[MAXN][MAXN];
int rea[MAXN][MAXN][MAXN][MAXN];
int dist[MAXN][MAXN];
long long counter[MAXN][MAXN];
queue<pair<int, int> > Q;

void init() {
	int i, j;

	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			scanf("%d", _data[i] + j);
			if (_data[i][j] == 3) {
				_data[i][j] = 0;
				sx = i;
				sy = j;
			}
			if (_data[i][j] == 4) {
				_data[i][j] = 0;
				ex = i;
				ey = j;
			}
		}
}

void solve() {
	int i, j, x, y;

	memset(rea, 0, sizeof(rea));
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (_data[i][j] == 0) {
				//                printf("i j %d %d\n",i,j);
				Q.push(make_pair(i, j));
				rea[i][j][i][j] = 1;
				while (!Q.empty()) {
					x = Q.front().first;
					y = Q.front().second;
					Q.pop();
					for (int k = 0; k < 8; k++)
						if (x + fx[k] >= 0 && x + fx[k] < m && y + fy[k] >= 0 && y + fy[k] < n && _data[x + fx[k]][y + fy[k]] == 1 && rea[i][j][x + fx[k]][y + fy[k]] == 0) {
							Q.push(make_pair(x + fx[k], y + fy[k]));
							rea[i][j][x + fx[k]][y + fy[k]] = 1;
						}
				}
				for (x = 0; x < m; x++)
					for (y = 0; y < n; y++)
						if (rea[i][j][x][y] == 1) {
							//                            printf("Lily Reachable %d %d\n",x,y);
							for (int k = 0; k < 8; k++)
								if (x + fx[k] >= 0 && x + fx[k] < m && y + fy[k] >= 0 && y + fy[k] < n && _data[x + fx[k]][y + fy[k]] == 0 && rea[i][j][x + fx[k]][y + fy[k]] == 0)
									rea[i][j][x + fx[k]][y + fy[k]] = 2;
						}
			}

	memset(dist, -1, sizeof(dist));
	dist[sx][sy] = 0;
	counter[sx][sy] = 1;
	Q.push(make_pair(sx, sy));
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		//        printf("%d %d : %d %I64d\n",x,y,dist[x][y],counter[x][y]);

		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (rea[x][y][i][j] == 2) {
					//                    printf("(%d %d) -> (%d %d)\n",x,y,i,j);
					if (dist[i][j] == -1) {
						dist[i][j] = dist[x][y] + 1;
						counter[i][j] = counter[x][y];
						Q.push(make_pair(i, j));
					}
					else
						if (dist[i][j] == dist[x][y] + 1)
							counter[i][j] += counter[x][y];
				}
	}
	//    while (1);
}

void output() {


	if (dist[ex][ey] == -1)
		cout << -1 << endl;
	else
		cout << dist[ex][ey] - 1 << endl << counter[ex][ey] << endl;
}

int main() {

	init();
	solve();
	output();

	return 0;
}