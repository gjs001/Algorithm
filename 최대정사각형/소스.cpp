#include <stdio.h>
#include <algorithm>

using namespace std;

char a[2000002];
int dp[1005][1005];

int main()
{
	register int i, j;
	int n, m;
	while (1) {
		scanf("%d %d\n", &n, &m);
		if (!n || !m)  return 0;
		int ans = 0;
		char *p = a;
		fread(a, 1, n*m << 1, stdin);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (*p == 48)
				{
					dp[i][j] = 0;
					p += 2;
					continue;
				}
				int a = min(dp[i - 1][j], dp[i - 1][j - 1]);
				dp[i][j] = min(a, dp[i][j - 1]) + 1;
				ans = max(ans, dp[i][j]);
				p += 2;
			}
		}

		printf("%d\n", ans);
	}
}