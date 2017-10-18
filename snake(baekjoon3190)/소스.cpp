#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define pii pair<int,int>
int n;
int k, l;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int apple[101][101];
int nd[10001];



class snake {
public:
	int taily;
	int tailx;
	int y;
	int x;
	int dir;
	int time;
	vector<pii> body;

	snake() {};
	snake(int ty, int tx, int ny, int nx, int nd, int t, vector<pii> b) {
		taily = ty, tailx = tx, y = ny, x = nx, dir = nd, time = t;
		body = b;
		body.push_back(make_pair(ny, nx));
		if (ty == -1 && tx == -1) {
			body.erase(body.begin());
			taily = body[0].first;
			tailx = body[0].second;
		}
	}
	
};
bool bodycheck(snake a,int ny, int nx) {
	vector<pii>::iterator iter;
	for (iter = a.body.begin(); iter != a.body.end(); ++iter) {
		if (ny == iter->first && nx == iter->second) return 0;
	}
	return 1;
}
int gosnake() {
	queue<snake> que;
	vector<pii> tmp;
	que.push(snake(1, 1, 1, 1, 0, 0,tmp));

	while (que.size()) {
		snake now = que.front();
		que.pop();
		int ny = now.y + dy[now.dir];
		int nx = now.x + dx[now.dir];
		int ndir = now.dir;
		if (nd[now.time + 1] != -1) {
			if (nd[now.time + 1]) {
				ndir = (ndir + 1) % 4;
			}
			else {
				ndir = (ndir - 1);
				if (ndir == -1) ndir = 3;
			}
		
		}
		if (ny > 0 && nx > 0 && ny <= n && nx <= n && bodycheck(now,ny,nx)) {
			if (apple[ny][nx]) {
				apple[ny][nx] = 0;
				que.push(snake(now.taily, now.tailx, ny, nx, ndir, now.time + 1,now.body));
			}
			else {
				que.push(snake(-1, -1, ny, nx, ndir, now.time + 1,now.body));
			}
		}
		else {
			return now.time + 1;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> y >> x;
		apple[y][x] = 1;
	}
	cin >> l;
	memset(nd, -1, sizeof(nd));
	for (int i = 0; i < l; i++) {
		int t;
		char d;
		cin >> t >> d;
		
		if (d == 'D')  nd[t] = 0;
		else if (d == 'L')  nd[t] = 1;


	}
	cout << gosnake();


}