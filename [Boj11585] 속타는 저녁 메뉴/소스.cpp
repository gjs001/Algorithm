#include <iostream>

using namespace std;

char str[1000005];
int pi[1000005];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 1, j = 0; str[i]; i++)
	{
		while (j && str[i] != str[j]) j = pi[j - 1];
		if (str[i] == str[j])
		{
			pi[i] = ++j;
		}
	}
	int ja, mo = n;
	if (pi[n - 1]) ja =  n / (n - pi[n - 1]);
	else ja = 1;
	if (mo%ja == 0) {
		mo /= ja; ja = 1;
	}
	cout << ja << '/' << mo;
}