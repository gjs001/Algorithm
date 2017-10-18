#include <iostream>

using namespace std;

int map[3][3];
int ans = 0;
int row_check()
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		int flag = 0;
		for (int j = 0; j < 3; j++)
		{
			if (!map[i][j])
			{
				flag = 1;
				break;
			}
			sum += map[i][j];
		}
		if (flag) continue;
		if (sum == 3)
			ans = 1;
		else if (sum == 6)
			ans = 2;
	}
	if (ans) return 1;
	else return 0;
}
int col_check()
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		int flag = 0;
		for (int j = 0; j < 3; j++)
		{
			if (!map[j][i])
			{
				flag = 1;
				break;
			}
			sum += map[j][i];
		}
		if (flag) continue;
		if (sum == 3)
			ans = 1;
		else if (sum == 6)
			ans = 2;
	}
	if (ans) return 1;
	else return 0;
}

int cross_check()
{
	int a =0;
	int b = 0;
	if(map[0][0] && map[1][1] && map[2][2])
		a = map[0][0] + map[1][1] + map[2][2];
	if(map[0][2] && map[1][1] && map[2][0])
		b = map[0][2] + map[1][1] + map[2][0];
	if (a == 3 || b == 3)
		ans = 1;
	else if (a == 6 || b == 6)
		ans = 2;
	if (ans) return 1;
	else return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start;
	cin >> start;
	for (int i = 0; i < 9; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y-1][x-1] = start;
		if (start == 2) start = 1;
		else start = 2;
		if(row_check()) break;
		if(col_check()) break;
		if(cross_check()) break;
	}
	
	cout << ans;
}