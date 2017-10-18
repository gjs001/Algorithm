#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int,int>
#define piii pair<int, pii>



int visit[1 << 6][51][51];
int w, h;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
char map[51][51];


class Data {
public:
	int key;
	int y, x, t;
	Data(){}
	Data(int a, int b, int c, int k) {
		t = a;
		y = b;
		x = c;
		key = k;
	}
	Data(int a, int b, int c) {
		t = a;
		y = b;
		x = c;
		key = 0;
	}

};

queue<Data> que;
int search() {
	while (que.size()) {
		Data now = que.front();
		que.pop();		
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < h && nx < w && !visit[now.key][ny][nx] && map[ny][nx] != '#') {
				if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
					int nk = now.key | (1 << (map[ny][nx] - 'a'));
					visit[nk][ny][nx] = 1;
					que.push(Data(now.t + 1, ny, nx, nk));
		
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {

					if ( now.key & (1 << (map[ny][nx] - 'A'))) {
						visit[now.key][ny][nx] = 1;
						que.push(Data(now.t + 1, ny, nx, now.key));
					}
				}
				else if (map[ny][nx] == '1') {
					return now.t + 1;
				}
				else {
					visit[now.key][ny][nx] = 1;
					que.push(Data(now.t + 1, ny, nx, now.key));
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j]=='0') 
			{
				que.push(Data(0,i,j));
				visit[0][i][j] = 1;
			}
		}
	}
	cout << search();


	
}