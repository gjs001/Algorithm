#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;


int s, e;

int dp[100004];


int main() {

	cin >> s >> e;
	
	for (int i = 0; i <= 100003; i++) dp[i] = abs(i-s);
	dp[s] = 0;
	if (s == e) cout << 0;
	else if (s < e) {
		int cur = s;
		while (cur != 100002) {
			if (cur * 2 <= 100000) dp[cur * 2] = min(dp[cur * 2], dp[cur] + 1);
			cur++;	
		}
		cur = s;
		while (cur != e + 2) {
			if (cur + 1 <= 100000) dp[cur + 1] = min(dp[cur + 1], dp[cur] + 1);
			if (cur - 1 >0) dp[cur - 1] = min(dp[cur - 1], dp[cur] + 1);
			if (cur * 2 <= 100000) dp[cur * 2] = min(dp[cur * 2], dp[cur] + 1);
			cur++;
		}
	}
	else {
		dp[e] = s - e;
	}
	cout << dp[e];
}