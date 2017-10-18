#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define max_s 55555

char t[max_s];
int n, m;
int ans;
int idx;
int b2[max_s] = { -1, };
using namespace std;
int getPi(string source)
{ 
	int ret = 0;
	for (int i = 0; i < source.length(); ++i) {
		string target = source.substr(i, source.length() - i);
		int size = target.length();
		vector<int> pi(size, 0);
		for (int j = 1, matched = 0; j < size; ++j) {
			while (matched > 0 && target[j] != target[matched]) matched = pi[matched - 1];
			if (target[j] == target[matched]) pi[j] = ++matched;
		}
		for (int j = 0; j < size; ++j)
			ret = max(ret, pi[j]);
		for (int j = 0; j < size; ++j)
		{
			if (b2[j] < pi[j]) b2[j] = pi[j];
		}
	}
	return ret;
}

int strlen_m(char *p)
{
	int res = 0;
	while (*p) {
		p++;
		res++;
	}
	return res;
}

void kmp_init(char *p)
{


	for (int k = 0; k < m - 1; k++)
	{
		int b[max_s] = { -1, };
		int j = -1;
		for (int i = k; i < m; i++)
		{
			while (j >= 0 && p[i] != p[j + k]) j = b[j];
			j++;
			if (b[i + 1 - k] < j)
			{
				b[i + 1 - k] = j;
				if (ans < j) ans = j;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.getline(t, max_s);

	m = strlen_m(t);

	do {
		ans = 0;
		kmp_init(t);
		int ans2 = getPi(t);
		if (ans != ans2)
		{
			cout << "error : "<< t << "\n";
		}
	} while (next_permutation(t, t + m));
}

