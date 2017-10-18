#include <iostream>
#include <cstring>
using namespace std;

int visit[100001];
int finish[100001];
int nextto[100001];
int n, t;
int ans;

void dfs(int s)
{
	visit[s] = 1;
	if (visit[nextto[s]])
	{
		if (!finish[nextto[s]])
		{
			int cnt = 0;
			int now = nextto[s];
			for (; now != s; now = nextto[now])
			{
				cnt++;
			}
			ans -= (cnt+1);
		}
	}
	else
	{
		dfs(nextto[s]);
	}
	finish[s] = 1;
}



int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = n;
		memset(visit, 0, sizeof(visit));
		memset(finish, 0, sizeof(finish));
		for (int i = 1; i <= n; i++)
			cin >> nextto[i];

		for (int i = 1; i <= n; i++)
		{
			if (!visit[i]) dfs(i);
		}
		cout << ans << "\n";
	}
}