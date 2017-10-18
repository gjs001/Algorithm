#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int w, h, t;
int map[51][51];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		int ans = 0;
		queue<int> que;
		vector<int> wait;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j]) wait.push_back(i*w + j);
			}
		}
		int size = wait.size();
		while (size) {
			while (size && que.empty()) {
				int tmp = wait[size - 1];
				wait.pop_back();
				size--;
				if (map[tmp / w][tmp%w]) que.push(tmp);
	
			}
			if (!size && que.empty()) break;
			while (!que.empty()) {
				int now = que.front();
				que.pop();
				int x = now%w;
				int y = now / w;
				for (int i = 0; i < 8; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 0) continue;
					map[ny][nx] = 0;
					que.push(ny*w + nx);
				}
			}
			ans++;
		}
		cout << ans << "\n";
	}
}