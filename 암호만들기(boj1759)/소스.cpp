#include <iostream>
#include <cstring>
#include <string>

using namespace std;
char text[29];
bool spell[29];
int l, c;
char mo[5] = { 'a','e','i','o','u' };
string ans;
void dfs(int n, char pass[29], int prev) {
	if (n == l) {
		int m = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < 5; j++) {
				if (pass[i]== mo[j]) m++;
			}
		}
		if (m > 0 && l - m > 1) {
			pass[l] = '\n';
			ans.append(pass);
		}
		return;
	}
	for (int i = prev+1; i < 28; i++) {
		if (spell[i]) {
			pass[n] = (char)(i + 'a');
			dfs(n + 1, pass, i);
		}
	}
}


int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char tmp;
		cin >> tmp;
		spell[tmp - 'a'] = 1;
	}
	
	dfs(0, text, -1);
	cout << ans;
}