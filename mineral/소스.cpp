#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

#define pii pair<int, int>
#define ground R+1
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0, 0, 1,-1 };

int R, C, N;
int stick[101];
int visit[101][101];
int vres[4];
char map[200][200];

vector<pii> shot(int now) {
	int idx = now;
	int depth = R - stick[idx] +1 ;
	vector<pii> a;
	if (now % 2 == 0) {
		for (int i = 0; i < C; i++) {
			if (map[depth][i] == 'x') {
				map[depth][i] = '.';
				a.push_back(make_pair(depth, i));
				return a;
			}
		}
	}
	else {
		for (int i = C-1; i >=0; i--) {
			if (map[depth][i] == 'x') {
				map[depth][i] = '.';
				a.push_back(make_pair(depth, i));
				return a;
			}
		}
	}
	a.push_back(make_pair(0,0));
	return 	a;
}

bool check(int idx,vector<pii> a, vector<pii> *p) {
	queue<pii> que;
	int y = a.front().first;
	int x = a.front().second;
	if (map[y][x] == '.') return 1;
	else que.push(make_pair(y, x));
	visit[y][x] = idx+1;
	p->push_back(make_pair(y, x));
	while (que.size()) {
		
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny > 0 && ny <= R && nx >= 0 && nx < C && !visit[ny][nx] && map[ny][nx] == 'x') {
				que.push(make_pair(ny, nx));
				visit[ny][nx] = idx+1;
				p->push_back(make_pair(ny, nx));
			}
			else if (vres[visit[ny][nx]-1]) {
				vres[idx] = 1;
				return 1;
			}
			else if (ny == ground) {
				vres[idx] = 1;
				return 1;
			}
		}
	}
	return 0;
}
void start() {
	int cnt = 0;
	int size = N;
	while (size--) {

		memset(visit, 0, sizeof(visit));
		memset(vres, 0, sizeof(vres));
		vector<pii> s;
		s = shot(cnt);
		int cy = s.front().first;
		int cx = s.front().second;
		if (cy == 0 && cx == 0) {
			cnt++;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			vector<pii> path;
			vector<pii> ns;
			int y = cy + dy[i];
			int x = cx + dx[i];
			ns.push_back(make_pair(y, x));
			if (!visit[y][x] && !check(i,ns,&path)) {
				bool flag = 1;
				while (flag) {
					int nvisit[101][101];
					memset(nvisit, 0, sizeof(nvisit));
					for (int i = 0; i < path.size(); i++) {
						int ny = path[i].first;
						int nx = path[i].second;
						nvisit[ny][nx] = 1;
					}
					for (int i = 0; i < path.size(); i++) {
					
						int ny = path[i].first;
						int nx = path[i].second;
						if (ny + 1 == ground || (map[ny + 1][nx] == 'x' && !nvisit[ny+1][nx])) flag = false;
					}
					if (flag) {
			
						for (int i = 0; i < path.size(); i++) {
							int ny = path[i].first;
							int nx = path[i].second;
							map[ny + 1][nx] = map[ny][nx];
							if(!nvisit[ny-1][nx])map[ny][nx] = '.';
							path[i].first = ny + 1;
						}
					}
				}
			}
		}
		/*for (int i = 1; i <= R; i++) {
			printf("%s\n", map[i]);
		}
		cout << stick[cnt] << '\n';
		if (cnt == 11) {
			cout << "this" << endl;
		}*/
		cnt++;
	}

}


int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		scanf("%s", &map[i]);
	}
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &stick[i]);


	start();

	for (int i = 1; i <= R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}