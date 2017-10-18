#include <iostream>
#include <algorithm>

using namespace std;

int t;
int day, month, threem, year;
int plan[13];
int dfs(int now)
{
	if (now >= 13) return 0;
	int ret = 0;
	int one = min(plan[now] * day, month);
	ret = min(one + dfs(now + 1), dfs(now + 3) + threem);
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> day >> month >> threem >> year;
		int ans = year;
		for (int i = 1; i <= 12; i++) cin >> plan[i];
		ans = min(ans, dfs(1));
		cout << "#" << testcase << " " << ans << "\n";
	}
}