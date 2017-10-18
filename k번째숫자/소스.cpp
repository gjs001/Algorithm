#include <iostream>

using namespace std;

int cp[100001];
int tarr[18][100001];
int* tree[1 << 18];
int n, m;
int lower_bound(int data, int size, int* arr)
{
	int s = 0;
	int e = size - 1;
	while (s != e)
	{
		int m = (s + e) / 2;
		if (arr[m] < data) s = m + 1;
		else e = m;
	}
	return e;
}

void set_tree(int s, int e, int depth) {
	if (s == e) {
		tarr[depth][s] = tarr[0][s];
	}
	else {
		int m = (s + e) / 2;
		int ls = s;
		int le = m;
		int rs = m + 1;
		int re = e;
		int cur = s;
		set_tree(ls, le, depth + 1);
		set_tree(rs, re, depth + 1);
		while (cur != e+1)
		{
			if ((ls != le && tarr[depth + 1][ls] < tarr[depth + 1][rs]) || rs == re )
			{
				tarr[depth][cur] = tarr[depth + 1][ls];
				ls++;
			}
			else
			{
				tarr[depth][cur] = tarr[depth + 1][rs];
				rs++;
			}
			cur++;
		}
	}
}

void init() {
	set_tree(0, n - 1, 0);
}


int main()
{

}