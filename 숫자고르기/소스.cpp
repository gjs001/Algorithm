#include <iostream>

using namespace std;

int finished[101];
int visit[101];
int n;
int nextto[101];
int color = 1;

int ans;
int anscur;

void dfs(int cur) {
	visit[cur] = 1;
	int res = 0;
	if (cur == nextto[cur]) {
		ans++;
		visit[cur] = ++color;
		return;
	}
	if (visit[nextto[cur]])
	{
		if (!finished[nextto[cur]])
		{
			color++;
			for (int i = nextto[cur]; i != cur; i = nextto[i])
			{
				res++;
				visit[i] = color;
			}
			res++;
			visit[cur] = color;
		}
		ans += res;
	}
	else
	{
		if(!visit[nextto[cur]])dfs(nextto[cur]);

	}
	finished[cur] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nextto[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i]) dfs(i);
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (visit[i]!= 1) cout << i << "\n";
	}

}