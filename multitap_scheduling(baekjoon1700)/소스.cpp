#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))
int qArr[101];
int nextnum[101];
int N, K;
int hole;
int ans;
bool cur[101];


void checknum(int tar, int start) {
	for (int i = start; i < K; i++) {
		if (tar == qArr[i])
		{
			nextnum[tar] = i;
			return;
		}
	}
	nextnum[tar] = K+1;
}


int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) scanf("%d", &qArr[i]);

	for (int i = 0; i < K; i++) {
		checknum(i, 0);
	}
	
	hole = N;
	int cnt = 0;
	while (cnt < K) {
		if (hole) {
			if (cur[qArr[cnt]]) {
				checknum(qArr[cnt], cnt + 1);
			}
			else {
				checknum(qArr[cnt], cnt + 1);
				cur[qArr[cnt]] = true;
				hole--;
			}
		}
		else {
			if (cur[qArr[cnt]]) {
				checknum(qArr[cnt], cnt + 1);
			}
			else{
				int mnum = 0;
				int idx;
				for (int i = 0; i < K; i++) {
					if (cur[i]) {
						if (mnum < nextnum[i]) {
							mnum = nextnum[i];
							idx = i;
						}
					}
				}
				cur[idx] = false;
				cur[qArr[cnt]] = true;
				checknum(qArr[cnt], cnt + 1);
				ans++;
			}
		}
		cnt++;
	}
	cout << ans;
}