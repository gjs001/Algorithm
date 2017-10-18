#include <iostream>
#include <algorithm>
using namespace std;

int stack[21];
int sidx;
void s_push(int data)
{
	stack[++sidx] = data;
}
int s_top() { return stack[sidx]; }
int s_pop() {
	return stack[sidx--];
}

int map[21][21];
int n;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int dfs(int depth, int nm[][21], int prev)
{
	int ans = 0;
	if (depth > 4) {
		for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	ans = max(ans, nm[i][j]);

		return ans;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (prev == i) continue;
			int d, s, e;
			if (dy[i]) d = 1;
			else d = 0;
			if (dy[i] < 0 || dx[i] < 0)	{s = 0;	e = n - 1;}
			else{ s = n - 1; e = 0;	}
			int t[21][21] = { 0, };
			for (int a = 0; a < n; a++)
			{
				int y, x;
				if (!d) y = a;
				else x = a;
				int issum = 0;
				for (int b = s; s<e?b <= e:b>=e; s<e?b++:b--)
				{
					if (!d) x = b;
					else y = b;
					if (nm[y][x])
					{
						if (sidx && s_top() == nm[y][x] && !issum)
						{
							s_push(s_pop() + nm[y][x]);
							issum = 1;
						}
						else {
							s_push(nm[y][x]);
							issum = 0;
						}
					}
				}
				if (!d) x = s < e? sidx-1 : s-sidx+1;
				else y = s< e ? sidx-1 : s- sidx+1;
				while (sidx)
				{
					t[y][x] = s_pop();
					if (!d) s < e ? x-- : x++;
					else s < e ? y-- : y++;
				}
			}
			ans = max(ans, dfs(depth + 1, t,i));
		}
		return ans;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	cout << dfs(0, map, -1);

}