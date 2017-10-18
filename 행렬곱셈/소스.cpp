#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int narr[502];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> narr[i] >> narr[i + 1];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{

		}
	}

	cout << dp[n][1];
}