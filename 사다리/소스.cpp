#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;

	for (int i = 1; i <= 10; i++)
	{
		cin >> t;
		int ans = -1;
		int mincnt = 10000;
		int map[101][101] = {};
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				cin >> map[j][k];
			}
		}
		for (int j = 0; j < 100; j++)
		{

			if (map[0][j])
			{
				int y = 0;
				int x = j;
				int sx = x;
				int cnt = 0;
				while (y < 100)
				{
					if (map[y][x + 1])
					{
						int nx = x + 1;
						while (nx < 100 && map[y][nx])
						{
							nx++;
							cnt++;
						}
						x = nx - 1;
						y = y + 1;
					}
					else if (map[y][x - 1])
					{
						int nx = x - 1;
						while (nx >= 0 && map[y][nx])
						{
							nx--;
							cnt++;
						}
						x = nx + 1;
						y = y + 1;
						
					}
					else
					{
						y = y + 1;
						cnt++;
					}
				}
				if(mincnt > cnt)
				{
					mincnt = cnt;
					ans = sx;
				}
			}
			
		}

		cout << "#" << i << " " << ans << "\n";
	}
}