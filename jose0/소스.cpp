#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>


using namespace std;
queue<int> A;
int ans[1001];
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) A.push(i + 1);
	int cnt = 0;
	int anscnt = 0;
	while (!A.empty()) {

		if (cnt == M - 1) {
			ans[anscnt++] = A.front();
			A.pop();
		}
		else {
			A.push(A.front());
			A.pop();
		}
		++cnt %= M;
	}
	printf("<");
	for (int i = 0; i < N; i++) {
		if (i == N - 1) printf("%d", ans[i]);
		else printf("%d, ", ans[i]);

	}
	printf(">");
}

