#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> P;
int t, n;
int map[11][11];
int dx[4] = { 1,-1 ,-1,1 };
int dy[4] = { 1,1 ,-1,-1 };

int check(int way[11], )


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n;
		int ans = -1;
		vector<P> man;
		vector<P> stair;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1) man.push_back(P(i, j));
				else if (map[i][j] == 2) stair.push_back(P(i, j));
			}
		}

		cout << "#" << testcase << " " << ans << "\n";
	}
}