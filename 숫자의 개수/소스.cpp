#include <iostream>

using namespace std;

int a, b, c;
int ans;
int narr[10];


int main() {
	cin >> a >> b >> c;
	ans= a*b*c;
	while (ans) {
		int tmp = ans % 10;
		narr[tmp]++;
		ans /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << narr[i] << "\n";
	}
}