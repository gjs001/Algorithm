
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

#define div 1000000000000000000
int n, m;
long long anscnt[101][101];
unsigned long long comb[101][101];
unsigned long long com(int n, int m) {
	if (comb[n][m]) return comb[n][m];
	if (m == 1) return comb[n][m] = n;
	if (m == 0 || n == m) return comb[n][m] = 1;
	else {
		comb[n][m] = com(n - 1, m - 1) + com(n - 1, m);
		anscnt[n][m] = anscnt[n - 1][m - 1] + anscnt[n - 1][m];
		if (comb[n][m] / div) anscnt[n][m] += comb[n][m] / div;
		return comb[n][m] %= div;
	}

}



int main() {
	cin >> n >> m;
	com(n, m);
	
	string ans;
	if (anscnt[n][m]) ans = to_string(anscnt[n][m]);
	string tmp;
	tmp = to_string(com(n, m));
	ans.append(tmp);
	cout << ans;
}