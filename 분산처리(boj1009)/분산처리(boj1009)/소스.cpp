#include <iostream>

using namespace std;


int cnt[10][4] = { {10,10,10,10}, {1,1,1,1},{2, 4, 8, 6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1} };

int t;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		a %= 10;
		b %= 4;
		if (b == 0) b = 4;
		cout << cnt[a][b -1] << "\n";
	}
}
