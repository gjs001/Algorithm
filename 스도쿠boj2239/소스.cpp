#include <iostream>
#include <cstring>

using namespace std;

int map[10][10];
int lv[10][10], cv[10][10], rv[10][10];

bool dfs(int cur)
{
	if (cur > 80) return true;
	int y = cur / 9;
	int x = cur % 9;
	if (map[y][x]) return dfs(cur + 1);
	else {
		for (int i = 1; i < 10; i++)
		{
			if (!lv[y][i])
			{
				if (!cv[x][i])
				{
					if (!rv[(y / 3) * 3 + x / 3][i])
					{
						map[y][x] = i;
						lv[y][i] = 1;
						cv[x][i] = 1;
						rv[(y / 3) * 3 + x / 3][i] = 1;
						if(dfs(cur + 1)) return true;
						map[y][x] = 0;
						lv[y][i] = 0;
						cv[x][i] = 0;
						rv[(y / 3) * 3 + x / 3][i] = 0;
					}
				}
			}
		}
	}
	return false;
}



int main() {

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < 9; i++)

	{
		for (int j = 0; j < 9; j++)
		{
			if (map[i][j])
			{
				lv[i][map[i][j]] = 1;
				cv[j][map[i][j]] = 1;
				rv[(i / 3) * 3 + j / 3][map[i][j]] = 1;
			}
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}