#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][3];
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	while (1)
	{
		cin >> n;
		t++;
		if (n == 0) return 0;
		int a, b, c;
		cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
		dp[0][0] = 1001;
		if (dp[0][2] < 0) dp[0][2] += dp[0][1];
		else dp[0][2] = 1001;
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b >> c;
			int idx = i % 2;
			int pidx = !idx;
			dp[idx][0] = min(dp[pidx][0], dp[pidx][1]) + a;
			dp[idx][1] = min(dp[idx][0],min(dp[pidx][0], min(dp[pidx][1], dp[pidx][2]))) + b;
			dp[idx][2] = min(dp[idx][1],min(dp[pidx][2], dp[pidx][1])) + c;
		}
		cout << t << ". " << dp[(n - 1) % 2][1] << "\n";
	}
	
}