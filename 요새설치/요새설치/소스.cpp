#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef pair<int, int> P;

int w, h;
char map[201][201];
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0, 0,1,-1 };
int next_to[201][201][4];
int main() {
	vector<P> a;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		char tmp;
		scanf("%c", &tmp);
		for (int j = 0; j < w; j++) {
			scanf("%c", &map[i][j]);
			if(map[i][j] == '.') a.push_back(P(i, j));
		}
	}
	for (auto now : a) {
		
		for (int i = 0; i < 4; i++) {
			int nx = now.second + dx[i];
			int ny = now.first + dy[i];
			while (map[ny][nx] == '.') {
				ny += dy[i];
				nx += dx[i];
			}
			next_to[now.first][now.second][i] = abs(ny-dy[i] - now.first) + abs(nx - dx[i] - now.second );
		}
	}
	int max = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			for (int k = 1; k < next_to[i][j][0]; k++) {
				if (i + 1 < h) {
					for (int t = 1; t <= next_to[i][j + k][2]; t++) {
						if (map[i + t][j] == 'X') break;
						if (next_to[i + t][j][0] >= k) {
							int tmp = (k+1)*(t+1);
							if (max < tmp) max = tmp;
						}
						
					}
				}
				if (i - 1 >= 0) {
					for (int t = 1; t <= next_to[i][j + k][3]; t++) {
						if (map[i - t][j] == 'X') break;
						if (next_to[i - t][j][0] >= k) {
							int tmp = (k + 1)*(t + 1);
							if (max < tmp) max = tmp;
						}
					}
				}
			}
			for (int k = 1; k < next_to[i][j][1]; k++) {
				if (i + 1 < h) {
					for (int t = 1; t <= next_to[i][j + k][2]; t++) {
						if (map[i + t][j] == 'X') break;
						if (next_to[i + t][j][1] >= k) {
							int tmp = (k + 1)*(t + 1);
							if (max < tmp) max = tmp;
						}
					}
				}
				if (i - 1 >= 0) {
					for (int t = 1; t <= next_to[i][j + k][3]; t++) {
						if (map[i - t][j] == 'X') break;
						if (next_to[i - t][j][1] >= k) {
							int tmp = (k + 1)*(t + 1);
							if (max < tmp) max = tmp;
						}
					}
				}
			}
		}
	}
	cout << max;
}