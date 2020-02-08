#include <iostream>
#include <cstring>
using namespace std;

int n, d;
long long k;
int dp[33][33];
char ans[35];
int cnt = 0;


int dfs(int now, int c)
{
	int& ret = dp[now][c];
	if (ret != -1) return ret;
	if (now == 0 || c == 0)return ret = 1;
	ret = dfs(now - 1, c);
	if(c > 0) ret += dfs(now - 1, c - 1);
	return ret;
}


int main(){
	cin >> n >> d >> k;
	memset(dp, -1, sizeof(dp));
	dfs(n, d);
	int now = n;
	int c = d;
	k--;
	while (k)
	{
		int next = dfs(now - 1,c);
		if (k < next)
		{
			ans[cnt++] = '0';
			now -= 1;
		}
		else {
			ans[cnt++] = '1';
			now -= 1;
			c -= 1;
			k -= next;
		}
	}
	for (int i = cnt; i < n; i++)
	{
		ans[i] = '0';
	}
	cout << ans;
}