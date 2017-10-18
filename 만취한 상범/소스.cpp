#include <iostream>
#include <cstring>

using namespace std;

int n, t;
int visit[101];


int main() {
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		memset(visit, 0, sizeof(visit));
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j+=i) {
				if (visit[j]) visit[j] = 0;
				else visit[j] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0)ans++;
		}
		cout << ans << "\n";
	}

}