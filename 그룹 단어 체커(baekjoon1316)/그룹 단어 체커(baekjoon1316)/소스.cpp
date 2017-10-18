#include <iostream>
#include <cstring>



int t;
using namespace std;


int main() {
	cin >> t;
	int ans = 0;
	while (t--) {
		char str[104];
		scanf("%s", &str);
		int visit[27] = { 0, };
		int start[27] = { 0, };
		char now = str[0];
		bool flag = 0;
		for (int i = 0; i < strlen(str); i++) {
			if (visit[str[i] - 'a']) {
				flag = 1;
				break;
			}
			start[str[i] - 'a'] = 1;
			if (now != str[i]) visit[now - 'a'] = 1;
			now = str[i];

		}
		if (!flag) ans++;
	}
	cout << ans;
}