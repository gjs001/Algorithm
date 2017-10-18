#include <iostream>

using namespace std;

int b, a, v;
int ans;
int main() {
	cin >> a >> b >> v;
	int c = a - b;
	int v2 = v - a;
	if (v2%c) ans = v2 / c + 1;
	else ans = v2 / c;
	ans++;
	cout << ans;
	

}