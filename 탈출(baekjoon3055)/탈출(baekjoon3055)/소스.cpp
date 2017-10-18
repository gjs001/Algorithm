#include <iostream>
#include <queue>

using namespace std;


typedef pair<int, int> P;
typedef pair<int, P> PP;

int visit[51][51];
char map[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
P s, d;
int w, h;


int main() {
	cin >> h >> w;
	queue<PP> que;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				s.first = i; s.second = j;
			}
			if (map[i][j] == 'D')
			{
				d.first = i; d.second = j;
			}
			if (map[i][j] == '*') 
				que.push(PP(-1, P(i, j)));
		}
	}
	que.push(PP(0, s));

	while (que.size()) {
		PP now = que.front();
		que.pop();
		if (now.second == d) {
			cout << now.first;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.second.first + dy[i];
			int nx = now.second.second + dx[i];
			if (ny >= 0 && nx >= 0 && ny < h && nx < w && !visit[ny][nx] && map[ny][nx] != '*' && map[ny][nx] != 'X') {
				
				if (now.first == -1) {
					if (map[ny][nx] == 'D') continue;
					map[ny][nx] = '*';
					que.push(PP(-1, P(ny, nx)));
				}
				else {
					que.push(PP(now.first + 1, P(ny, nx)));
				}
				visit[ny][nx] = 1;
			}
		}
	}
	cout << "KAKTUS";
}