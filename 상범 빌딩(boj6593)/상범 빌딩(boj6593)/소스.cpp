#include <iostream>
#include <queue>
#include <cstring>
#include <functional>


using namespace std;


#define INF 987654321

typedef struct oper {
	int z, y, x;
	oper() {
		
		y = 0;
		x = 0;
		z = 0;
	}
	oper(int a, int b, int c) {
		z = a, y = b, x = c;
	}

};
typedef pair<int, oper> P;

bool operator < (P a ,P b) {
	return a.first < b.first;
}

bool isEqual(oper a, oper b) {
	if (a.z == b.z) if (a.y == b.y) if (a.x == b.x) return true;
	return false;
}


int l, r, c;
int visit[31][31][31];
int dist[31][31][31];
char map[31][31][31];

int dy[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

int main() {
	std::ios::sync_with_stdio(false);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0) break;
		oper Start, End;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					dist[i][j][k] = INF;
					if (map[i][j][k] == 'S') Start = oper(i, j, k);
					if (map[i][j][k] == 'E') End = oper(i, j, k);
				}
			}
		}
		bool flag = 0;
		priority_queue < pair<int, oper>, vector<pair<int, oper>>, greater<pair<int, oper>>> que;
		que.push(P(0, Start));
		while (que.size()) {
			P now = que.top();
			que.pop();
			if (isEqual(End, now.second)) {
				cout << "Escaped in " << now.first << " minute(s).\n";
				flag = 1;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int nz = now.second.z + dz[i];
				int ny = now.second.y + dy[i];
				int nx = now.second.x + dx[i];
				if (nz < 0 || nz >= l || ny < 0 || ny >= r || nx < 0 || nx >= c || map[nz][ny][nx] == '#' || visit[nz][ny][nx] || dist[nz][ny][nx] < now.first +1) continue;
				int ndist = now.first + 1;
				visit[nz][ny][nx] = 1;
				dist[nz][ny][nx] = min(dist[nz][ny][nx], now.first + 1);
				que.push(P(ndist, oper(nz, ny, nx)));
			}
		}
		if (!flag) cout << "Trapped!\n";
		
	}
}

