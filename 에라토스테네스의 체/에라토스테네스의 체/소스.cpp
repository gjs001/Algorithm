#include <stdio.h>

int ans;
int n, k;
bool arr[1001];


int main() {
	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++) {
		if (arr[i]) continue;
		ans++;
		arr[i] = 1;
		if (k == ans) {
			printf("%d", i);
			break;
		}
		for (int j = i; j <= n; j += i) {
			if(arr[j]) continue;
			arr[j] = 1;
			ans++;
			if (k == ans) {
				printf("%d", j);
				return 1;
			}
		}
	}
}