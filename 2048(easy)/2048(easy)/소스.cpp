#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
#define U 0
#define D 1
#define R 2
#define L 3
typedef vector<vector<int>> VI;
typedef pair<int, VI> PV;
VI map;
queue<PV> m;
int da[4];
int db[4];
void move(int dir, VI c, int cnt) {
	if (dir == U) {
		for (int i = 0; i < n; i++) {
			int cur = 0;
			int init = 1;
			for (int j = 0; j < n; j++) {
				if (init) {
					if (c[j][i]) {
						cur++;
						continue;
					}
					else {
						init = 0;
					}
				}
				if (c[j][i] == 0) {
					continue;
				}
				c[cur][i] = c[j][i];
				c[j][i] = 0;
				cur++;
				
			}
			cur = 0;

			for (int j = 0; j < n; j++) {

				if (c[j][i] == 0) {
					continue;
				}
				if (j + 1 < n && c[j][i] != 0 && c[j][i] == c[j + 1][i]) {
					c[cur][i] = c[j][i] * 2;
					if (cur != j) c[j][i] = 0;
					c[j + 1][i] = 0;
					}
				else if(c[cur][i] == 0) {
					
					c[cur][i] = c[j][i];
					c[j][i] = 0;
				}
				cur++;
			}
		}
	}
	if (dir == D ) {

		for (int i = 0; i < n; i++) {
			int cur = n-1;
			int init = 1;
			for (int j = n-1; j >= 0; j--) {
				if (init) {
					if (c[j][i]) {
						cur--;
						continue;
					}
					else {
						init = 0;
					}
				}
				if (c[j][i] == 0) {
					continue;
				}
				c[cur][i] = c[j][i];
				c[j][i] = 0;
				cur--;
			}
			cur = n-1;
			for (int j = n-1; j >= 0; j--) {
				if (c[j][i] == 0) {
					continue;
				}
				if (j - 1 >=0 && c[j][i] != 0 && c[j][i] == c[j - 1][i]) {
					c[cur][i] = c[j][i] * 2;
					if (cur != j) c[j][i] = 0;
					c[j - 1][i] = 0;
					
				}
				else if (c[cur][i] == 0) {
					c[cur][i] = c[j][i];
					c[j][i] = 0;
				}
				cur--;
			}
		}
	}
	if (dir == L) {

		for (int i = 0; i < n; i++) {
			int cur = 0;
			int init = 1;
			for (int j = 0; j < n; j++) {
				if (init) {
					if (c[i][j]) {
						cur++;
						continue;
					}
					else {
						init = 0;
					}
				}
				if (c[i][j] == 0) {
					continue;
				}
				c[i][cur] = c[i][j];
				c[i][j] = 0;
				cur++;

			}
			cur = 0;
			init = 1;
			for (int j = 0; j < n; j++) {
				if (c[i][j] == 0) {
					continue;
				}
				if (j + 1 < n && c[i][j] == c[i][j+1]) {
					c[i][cur] = c[i][j] * 2;
					if (cur != j) c[i][j] = 0;
					c[i][j+1] = 0;
					
				}
				else  if (c[i][cur] == 0) {
					c[i][cur] = c[i][j];
					c[i][j] = 0;
				}
				cur++;
			}
		}
	}
	if (dir == R) {

		for (int i = 0; i < n; i++) {
			int cur = n-1;
			int init = 1;
			for (int j = n-1; j >= 0; j--) {
				if (init) {
					if (c[i][j]) {
						cur--;
						continue;
					}
					else {
						init = 0;
					}
				}
				if (c[i][j] == 0) {
					continue;
				}
				c[i][cur] = c[i][j];
				c[i][j] = 0;
				cur--;

			}
			cur = n-1;
			for (int j = n-1; j >= 0 ; j--) {

				if (c[i][j] == 0) {
					continue;
				}
				if (j - 1 >=0 && c[i][j] != 0 && c[i][j] == c[i][j - 1]) {
					c[i][cur] = c[i][j] * 2;
					if (cur != j) c[i][j] = 0;
					c[i][j - 1] = 0;
					
				}
				else if (c[i][cur] == 0) {
					c[i][cur] = c[i][j];
					c[i][j] = 0;
				}
				cur--;
			}
		}
	}
	m.push(PV(cnt + 1, c));
}

int main() {
	cin >> n;
	map.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n,0);
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int max = 0;
	da[1] = da[2] = n;
	db[0] = db[3] = n;
	m.push(PV(0,map));

	while (m.size()) {
		PV now = m.front();
		m.pop();
		if (now.first == 5) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (max < now.second[i][j]) max = now.second[i][j];
				}
			}
			continue;
		}
		for (int i = 0; i < 4; i++) {
			move(i, now.second, now.first);
		}

	}
	cout << max;

	int as[30][30];

}