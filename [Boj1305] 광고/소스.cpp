#include <iostream>

using namespace std;

int n, pi[1000005];
char str[1000005];

inline void init() {
	for (int i = 1, j = 0; str[i]; i++)
	{
		while (j && str[i] != str[j]) j = pi[j-1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> str;
	init();
	cout << n - pi[n - 1];
}