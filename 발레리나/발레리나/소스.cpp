#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 31*31

typedef struct dance {
	int y;
	int x;
	int b;
	long long d;
};

typedef pair<int, int> P;

int h, w;
int map[31][31];
int visit[31][31];
int check[31][31];
long long dist[31][31];
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
dance start;
dance t;


int main() {
	ios::sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[i][j] = INF;
			dist[i][j] = 0;
			cin >> map[i][j];
			if (map[i][j] == 3) {
				start.y = i;
				start.x = j;
				visit[i][j] = 0;
				dist[i][j] = 1;
			}
			if (map[i][j] == 4) {
				t.y = i;
				t.x = j;
			}

		}
	}

	start.b = 0;
	start.d = 1;
	queue<dance> que;
	que.push(start);
	queue<dance> que2;
	while (!que.empty()) {
		dance now = que.front();
		que.pop();
		
		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 2) continue;
			if (map[ny][nx] && visit[ny][nx] <= now.b) continue;
			if (!map[ny][nx] && visit[ny][nx] <= now.b + 1) continue;
			visit[ny][nx] = now.b;
			dance tmp;
			tmp.y = ny;
			tmp.x = nx;
			tmp.b = now.b;
			if (!map[ny][nx]) {
				tmp.b++;
				visit[ny][nx]++;
			}
			que.push(tmp);
		}
	}
	que.push(start);
	vector<dance> wait[931];
	while(!que.empty()){

		while (!que.empty()) {
			dance now = que.front();
			que.pop();
			int visit2[31][31];
			memset(visit2, 0, sizeof(visit2));
			for (int i = 0; i < 8; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 2) continue;
				if (map[ny][nx] && visit[ny][nx] < now.b) continue;
				if (!map[ny][nx] && visit[ny][nx] < now.b + 1) continue;
				dance tmp;
				tmp.y = ny;
				tmp.x = nx;
				tmp.b = now.b;
				tmp.d = now.d;
				if (!map[ny][nx]) {
					tmp.b++;
					visit2[tmp.y][tmp.x] = 1;
					if (dist[ny][nx] == 0) {
						wait[tmp.b].push_back(tmp);
						dist[ny][nx] += now.d ;
					}
					else {
						dist[ny][nx] += now.d;
					}
				}
				else if (map[ny][nx] == 4) {
					dist[ny][nx] += now.d;
				}
				else {
					visit2[tmp.y][tmp.x] = 1;
					que2.push(tmp);
					}
					
				}
			while (!que2.empty()) {
				dance now2 = que2.front();
				que2.pop();
				for (int j = 0; j < 8; j++) {
					int ny2 = now2.y + dy[j];
					int nx2 = now2.x + dx[j];
					if (ny2 < 0 || nx2 < 0 || ny2 >= h || nx2 >= w || map[ny2][nx2] == 2 || visit2[ny2][nx2]) continue;
					if (map[ny2][nx2] && visit[ny2][nx2] < now2.b) continue;
					if (!map[ny2][nx2] && visit[ny2][nx2] < now2.b + 1) continue;
					dance tmp2;
					tmp2.y = ny2;
					tmp2.x = nx2;
					tmp2.b = now2.b;
					tmp2.d = now2.d;
					if (!map[ny2][nx2]) {
						tmp2.b++;
						visit2[ny2][nx2] = 1;
						if (dist[ny2][nx2] == 0) {

							wait[tmp2.b].push_back(tmp2);
							dist[ny2][nx2] += now2.d;
						}
						else {
							dist[ny2][nx2] += now2.d;
						}
					}
					else if (map[ny2][nx2] == 4) {
						dist[ny2][nx2] += now2.d;
					}
					else {
						que2.push(tmp2);
						visit2[tmp2.y][tmp2.x] = 1;
					}
				}
				
			}
		}
		int next = -1;
		if (visit[t.y][t.x] == INF) break;
		for (int i = 0; i <= visit[t.y][t.x]; i++) {
			if (wait[i].empty()) continue;
			next = i;
			break;
		}
		if (next != -1) {
			int ws = wait[next].size();
			for (int i = ws -1; i >= 0; i--) {
				dance tmp = wait[next][i];
				tmp.d = dist[tmp.y][tmp.x];
				que.push(tmp);
				wait[next].pop_back();
			}
		}

	}


	if (visit[t.y][t.x] == INF) cout << -1;
	else cout << visit[t.y][t.x] << "\n" << dist[t.y][t.x];
	
}