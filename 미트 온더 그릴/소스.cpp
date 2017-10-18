#include <iostream>
#include <cstring>
using namespace std;

char map[12][12];
char nm[12][12];
int t, h, w;


int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		memset(nm, 0, sizeof(nm));
		cin >> h >> w;
		for (int i = 0; i < h; i++) cin >> map[i];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				nm[i][j] = map[i][w - j - 1];
			}
		}
		for (int i = 0; i < h; i++)
			cout << nm[i] << "\n";
	}

}