#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
int narr[4001];
int dp[4001];
char ans[10000000];
int acnt;
const int DUMMY = 100001;

inline void init()
{
	int R = 0;
	int Ridx = 0;
	for (int i = 1; i < 2 * n - 1; i++)
	{
		if(i <= R)dp[i] = min(R - i, dp[2*Ridx - i]);
		else dp[i] = 0;

		while (i - dp[i] - 1 >= 0 && i + dp[i] +1 < 2*n -1 && narr[i - dp[i] - 1] == narr[i + dp[i] + 1])
		{
			dp[i]++;
		}
		if (dp[i] > 0 && narr[i - dp[i]] == DUMMY) dp[i]--;

		if (R < i + dp[i])
		{
			R = i + dp[i];
			Ridx = i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> narr[0];
	for (int i = 1; i < n; i++)
	{
		narr[2 * i - 1] = DUMMY;
		cin >> narr[2 * i];
	}
	init();

	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		int idx = a + b - 2;
		if (a == b || (dp[idx] > 0 && dp[idx] >= b - a)) ans[acnt++] = '1';
		else ans[acnt++] = '0';
		ans[acnt++] = '\n';
	}
	cout << ans;
}