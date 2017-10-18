#include <iostream>

using namespace std;

int k;
int n;
int narr[100001];
int main() {
	scanf("%d", &k);
	char tmp = 0;
	getchar();
	int cnt = 0;
	while ((tmp = getchar()) != '\n') {
		n += (int)(tmp - '0');
		narr[cnt++] = (int)(tmp - '0');
	}
	if (k <= n) printf("0");
	else {
		int start = cnt - 1;
		int dif = k - n;
		int ans = 0;
		while (dif > 0) {
			dif -= (9 -narr[start--]);
			ans++;
		}
		cout << ans;
	}

}