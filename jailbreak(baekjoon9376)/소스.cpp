#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

#define coor(y,x,n) (y*n+x)
#define toX(a,n) (a%n)
#define toY(a,n) (a/n)
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 2000000000
#define gate 100000
#define pii pair<int,int>

int t, w, h, e, mh, mw;
int dist[130][130];
int save[3][130 * 130];
bool visit[130][130];

int ans;
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0,0,1,-1 };
int graph[130][130];
int sArr[600];
int scnt;
char map[130][130];

//string sa;

bool search(int s, int k) { //다익스트라
	priority_queue<pii, vector<pii>, greater<pii> > que;
	int sx = toX(s, mw);
	int sy = toY(s, mw);
	
	
		que.emplace(graph[sy][sx], s);
		visit[sy][sx] = 1;
		dist[sy][sx] = graph[sy][sx];
	
	while (que.size()) {
		int cur = que.top().second;
		int x = toX(que.top().second, mw);
		int y = toY(que.top().second, mw);
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < mw && ny >= 0 && ny < mh && !visit[ny][nx] && map[ny][nx] != '*') {
					
				dist[ny][nx] = min(dist[ny][nx], dist[y][x] + graph[ny][nx]);
				visit[ny][nx] = 1;
				que.emplace(dist[ny][nx], coor(ny, nx, mw));
										
			}
		}
		

	}
	
	return 0;
}

int main() {
	cin >> t;
	while (t--) {
		memset(sArr, 0, sizeof(sArr));
		scnt = 0;
		cin >> h >> w;
		mh = h + 2;
		mw = w + 2;
		for (int i = 1; i <= h; i++) {
			char tmp;
			scanf("%c", &tmp);
			for (int j = 1; j <= w; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '*') {
					graph[i][j] = INF;
				}
				if (map[i][j] == '#') {
					graph[i][j] = gate;
				}
				if (map[i][j] == '.') {
					graph[i][j] = 1;
				}
				if (map[i][j] == '$') {
					graph[i][j] = 0;
					sArr[scnt++] = coor(i, j, mw);
				}
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < mh; i++) { // 그래프 외곽에 보이지 않는 길을 만들어준다.
			for (int j = 0; j < mh; j++) {
				if ((i == 0 || i == h + 1 || j == 0 || j == w + 1)) {
					map[i][j] = ' ';
					graph[i][j] = 0;
					dist[i][j] = INF;
				}
			}
		}


		sArr[scnt++] = 0; //임의의 시작점 추가

		for (int k = 0; k < scnt; k++) {
			search(sArr[k], k);
			for (int i = 0; i < mh; i++) {
				for (int j = 0; j < mw; j++) {
					int cur = coor(i, j, mw);
					save[k][cur] = dist[i][j];
				}
			}
			memset(visit, 0, sizeof(visit));
			for (int i = 0; i < mh; i++)
				for (int j = 0; j < mw; j++)
					dist[i][j] = INF;

		}

		ans = INF;
		for (int i = 0; i < mh*mw; i++) {
			if (toX(i, mw) > 0 && toX(i, mw) <= w && toY(i, mw) > 0 && toY(i, mw) <= h) {
				int sum = save[0][i] + save[1][i] + save[2][i];
				ans = min(ans, ((map[toY(i, mw)][toX(i, mw)] == '#' ? -2 : 0)*gate + sum));
			}
		}
		ans /= gate;

		cout << ans << endl;

			//데이터 확인용 파일출력
			/*
			ofstream out("output.txt");
			char buf[128];
			sprintf(buf, "%d", mAns);
			sa.append(buf);
			sa.append("\n");
			out << sa;
			out.close();*/

	}

}


