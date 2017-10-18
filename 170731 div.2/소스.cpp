#include <iostream>

using namespace std;

int n, q, c;
int map[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q >> c;
	for (int i = 1; i <= 100; i++) for (int j = 1; j <= 100; j++) map[i][j] = -1;
	for (int i = 0; i < n; i++) {
		int y, x, s;
		cin >> x >> y >> s;
		map[y][x] = s;
	}

	for (int i = 0; i < q; i++) {
		int t,x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int nt = t % (c + 1);
		int sum = 0;
		for (int a = y1; a <= y2; a++) {
			for (int b = x1; b <= x2; b++) {
				if (map[a][b] != -1) {
					int tmp = map[a][b] + nt;
					tmp %= (c + 1);
					sum += tmp;
				}
			}
		}
		cout << sum << "\n";
	}

}