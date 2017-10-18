#include <iostream>

using namespace std;

long long get_max(int n)
{
	if (n == 0) return 1;
	return get_max(n - 1) * 3 + 2;
}
long long get_min(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++) res *= 3;
	return res + n * 2;
}
int main()
{
	int n = 19;
	cout << get_min(n) << " ~ " << get_max(n);
}