#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

char map[6][6];
int dist[6][6];
P check[5];
int cnt;

int getdist(P a, P b)
{
	return abs(a.first - b.first) + abs(a.second - b.second) -1;
}


int main()
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
			{
				check[cnt++] = P(i, j);
			}
		}
	}
	if (cnt == 1) cout << 0;
	else if (cnt == 2) cout << getdist(check[0], check[1]);
	else 
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < cnt; k++)
				{
					dist[i][j] += abs(check[k].first - i) + abs(check[k].second - j);
				}
			}
		}
		int ans = 25;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				ans = min(ans, dist[i][j]);
			}
		}
		if (cnt == 3) cout << ans - cnt + 1;
		else if (cnt == 4) cout << ans - cnt;
		else cout << ans - cnt - 1;
	}
	

}