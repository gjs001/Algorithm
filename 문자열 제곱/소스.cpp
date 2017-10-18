#include <iostream>
#include <cstring>


using namespace std;
int pi[1010010];
char s[1010010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("d.in", "r", stdin);
	while (1)
	{
		int i, j;
		cin >> s;
		if (s[0] == '.') break;
		for (pi[i = 0] = j = -1; s[i] > 32; j < 0 | s[i] == s[j] ? pi[++i] = ++j : j = pi[j]);
		printf("%d\n", i % (i - pi[i]) ? 1 : i / (i - pi[i]));
	
	}
	return 0;
}
