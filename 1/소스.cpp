#include <iostream>
#include <cstring>
using namespace std;

char patt[100005];
bool spell[29];
int n;

int main() {
	//ios::sync_with_stdio(false);
	char tmp;
	while ((tmp = getchar()) != '\n') {
		spell[tmp - 'a'] = 1;
	}
	cin >> patt;
	cin >> n;
	while (n--) {
		char tc[100005];
		int cnt1 = 0;
		int cnt2 = 0;
		cin >> tc;
		bool ans = 0;
		while (1) {
			if (patt[cnt1] == 0 && tc[cnt2] == 0) {
				ans = 1;
				break;
			}
			else if (patt[cnt1] == 0) break;
			else if (tc[cnt2] == 0 && patt[cnt1] != '*') break;
			else if (patt[cnt1] != '?' && patt[cnt1] != '*') {
				if (patt[cnt1] != tc[cnt2]) break;
			}
			else if (patt[cnt1] == '?') {
				if (spell[tc[cnt2]- 'a'] == 0) break;
			}
			else {
				if (tc[cnt2] != 0 && spell[tc[cnt2]- 'a']) break;
				if (tc[cnt2] == 0) {
					ans = 1;
					break;
				}
				int size = strlen(tc);
				int psize = strlen(patt);
				bool flag = 0;
				for (int i = cnt2; i < size; i++) {
					if (spell[tc[i] - 'a'] == 1) {
						if (patt[cnt1 + 1] == '?') {
							cnt2 = i - 1;
							break;
						}
						else if (tc[i] != patt[cnt1 + 1]) {
							flag = 1;
							break;
						}
						else {
							cnt2 = i - 1;
							break;
						}
					}
					if (psize - cnt1 == size -i && patt[cnt1 + 1] == tc[i]) {
						cnt2 = i;
						break;
					}
					if (i == size - 1 && psize - cnt1 > 1) {
						flag = 1;
						break;
					}
					if (i == size - 1) cnt2 = i;
				}
				
				if (flag) break;
				
			}

			if (patt[cnt1] != 0)cnt1++;
			if (tc[cnt2] != 0)cnt2++;
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

	
}