#include <iostream>

using namespace std;

int dp[1100];

int main() {
	int a, b;
	int cnt = 1;
	cin >> a >> b;

	for (int i = 1; cnt <= 1000; i++) {
		for (int j = 0; j < i; j++) {
			dp[cnt] = i + dp[cnt-1];
			cnt++;
		}
	}
	cout << dp[b] - dp[a-1];
}