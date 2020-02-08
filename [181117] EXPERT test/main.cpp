#include <iostream>
#include <random>

using namespace std;

const int SIZE = 64;
const int SEED = 3;
unsigned char image[SIZE][SIZE];
int COUNT,RESULT;


int get_rand()
{
	return rand();
}

extern int calrec(unsigned char image[SIZE][SIZE]);


void rect() {
	int sy, sx, ey, ex;
	while (true)
	{
		sy = get_rand()%SIZE;
		sx = get_rand()%SIZE;
		ey = get_rand()%SIZE;
		ex = get_rand()%SIZE;
		if (sy > ey)
		{
			int tmp = ey;
			ey = sy;
			sy = tmp;
		}
		if (sx > ex)
		{
			int tmp = ex;
			ex = sx;
			sx = tmp;
		}
		if (ey - sy < 9) continue;
		if (ex - sx < 9) continue;
		break;
	}
	for (int i = sy; i < ey; i++)
	{
		for (int j = sx; j < ex; j++)
		{
			image[i][j]++;
		}
	}
	if (ey - sy == ex - sx) COUNT++;
}

void make() {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			image[i][j] = 0;
		}
	}
	
	for (int i = 0; i < 50; i++)
	{
		rect();
	}
}

int main()
{
	srand(SEED);
	for (int i = 0; i < 10000; i++)
	{
		COUNT = 0;
		make();
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				printf("%2d ",image[i][j]);
			}
			cout << "\n";
		}
		if (COUNT == calrec(image)) RESULT++;
	}
	cout << RESULT;
}