#include <iostream>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int t, h, w, n,tank;
char map[21][21];
char command[103];
char tank_shape[4] = { '^','>','v','<' };
int tank_dir = 0;
void move(char c)
{
	int dir;
	if (c == 'U') dir = 0;
	else if (c == 'R') dir = 1;
	else if (c == 'D') dir = 2;
	else dir = 3;

	int ty = tank / w;
	int tx = tank % w;
	map[ty][tx] = tank_shape[dir];
	int ny = ty + dy[dir];
	int nx = tx + dx[dir];
	if (ny >= 0 && ny < h && nx >= 0 && nx < w && map[ny][nx] == '.')
	{
		map[ny][nx] = tank_shape[dir];
		map[ty][tx] = '.'; 
		tank = ny*w + nx;
	}
	tank_dir = dir;
}

void Shoot()
{
	int cy = tank / w + dy[tank_dir];
	int cx = tank % w + dx[tank_dir];
	while (cy >= 0 && cy < h && cx >= 0 && cx < w && (map[cy][cx] == '.' || map[cy][cx] == '-'))
	{
		cy += dy[tank_dir];
		cx += dx[tank_dir];
	}
	if (cy >= 0 && cy < h && cx >= 0 && cx < w && map[cy][cx] == '*') map[cy][cx] = '.';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++) cin >> map[i];
		cin >> n >> command;

		for (int i = 0; i < h*w; i++)
		{
			int y = i / w;
			int x = i % w;
			for (int j = 0; j < 4; j++)
			{
				if (map[y][x] == tank_shape[j])
				{
					tank = i;
					tank_dir = j;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			char now_cmd = command[i];
			if (now_cmd == 'S') Shoot();
			else move(now_cmd);
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < h; i++)
		{
			cout << map[i] << "\n";
		}
	}
}