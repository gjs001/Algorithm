#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[51][51];
struct house {
	int y;
	int x;
	int cost[13];
	house() { x = y = 0;}
}arr[101];

struct ck {
	int y;
	int x;
}cka[15];

int hcnt = 0;
int kcnt = 0;


int check(int a)
{
	int res = 0;
	while (a)
	{
		a -= a&-a;
		res++;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				arr[hcnt].y = i;
				arr[hcnt++].x = j;
			}
			else if (map[i][j] == 2)
			{
				cka[kcnt].y = i;
				cka[kcnt++].x = j;
			}
		}
	for (int i = 0; i < kcnt; i++)
	{
		int cy = cka[i].y;
		int cx = cka[i].x;
		for (int j = 0; j < hcnt; j++)
		{
			int hy = arr[j].y;
			int hx = arr[j].x;
			arr[j].cost[i] = abs(cy - hy) + abs(cx - hx);
		}
	}
	int answer = 99999;
	for (int i = 1; i < (1 << kcnt); i++)
	{
		if (check(i) != m) continue;
		int sum = 0;
		for (int j = 0; j < hcnt; j++)
		{
			int res = 9999;
			for (int k = 0; k < kcnt; k++)
			{
				if (i & (1 << k) && res > arr[j].cost[k])
				{
					res = arr[j].cost[k];
				}
			}
			sum += res;
		}
		answer = min(answer, sum);
	}
	cout << answer;
}