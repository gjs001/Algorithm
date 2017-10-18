#include <iostream>

using namespace std;

int n;
int s[110];
int ans[1000];
int a;
int main() {
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%1d",&s[i]);
	}
	int now = 0;
	while (now < n) {
		if (s[now] == 1) {
			int cnt = 0;
			while (s[now] == 1 && now < n) {
				cnt++;
				now++;
			}
			ans[a++] = cnt;
		}
		else {
			int cnt = 0;
			while (s[now] == 0 && now <n) {
				cnt++;
				now++;
			}
			while (cnt - 1) {
				ans[a++] = 0;
				cnt--;
			}
			if (now == n && cnt == 1) ans[a++] = 0;
		}
	}
	for (int i = 0; i < a; i++) cout << ans[i];
}