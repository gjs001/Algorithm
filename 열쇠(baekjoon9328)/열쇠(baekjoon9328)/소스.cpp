#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>


using namespace std;
typedef pair<int, int> P;

char map[105][105];
int w, h;
int t;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int check[105][105];
int key[27];
int visit[105][105][30];

int main() {
	cin >> t;


	while (t--) {
		cin >> h >> w;
		int ans = 0;

		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));
		memset(key, 0, sizeof(key));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (i > 0 && i < h + 1 && j > 0 && j < w + 1) continue;
				map[i][j] = '.';
			}
		}
			
		string initkey;
		cin >> initkey;

		if (initkey != "0") {
			for (int i = 0; i < initkey.size(); i++) {
				key[initkey[i] - 'a'] = 1;
			}
		}
		
		queue<P> que;
		vector<P> door[27];
		que.push(P(0, 0));
		string tmp;
		char a[100];
		visit[0][0][0] = 1;
		int cnt = 0;
		while (que.size()) {
			P now = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];
				if (ny < 0 || nx <0 || ny > h + 1 || nx > w + 1 || visit[ny][nx][cnt] || map[ny][nx] == '*') continue;
				if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
					if (key[map[ny][nx] - 'a']) {
						visit[ny][nx][cnt] = 1;
						que.push(P(ny, nx));
					}
					else {
						for(int i=0;i<door[map[ny][nx] - 'a'].size();i++){
							que.push(door[map[ny][nx] - 'a'][i]);
						}
						door[map[ny][nx] - 'a'].clear();
						cnt++;
						key[map[ny][nx] - 'a'] = 1;
						visit[ny][nx][cnt] = 1;
						que.push(P(ny, nx));
					}

				}
				if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
					if (key[map[ny][nx] - 'A'] != 1) {
						door[map[ny][nx] - 'A'].push_back(P(ny, nx));
						}
					else {
						visit[ny][nx][cnt] = 1;
						que.push(P(ny, nx));
					}
				}
				if (map[ny][nx] == '$') {
					if (!check[ny][nx]) {
						ans++;
						check[ny][nx] = 1;
					}
					visit[ny][nx][cnt] = 1;
					que.push(P(ny, nx));
				}
				if (map[ny][nx] == '.') {
					visit[ny][nx][cnt] = 1;
					que.push(P(ny, nx));
				}
			}
		}
		cout << ans << "\n";
	
		
	}

}
