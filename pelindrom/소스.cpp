#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <cstring>

using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

int N;
char strarr[2503];
bool mem[2501][2501];
int ans[2501];


int main() {
	cin >> strarr;
	N = strlen(strarr);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (i == j) mem[i][j] = true;
			else if (i == j - 1 && strarr[i] == strarr[j]) mem[i][j] = true;
			else if (mem[i + 1][j - 1] == true && strarr[i] == strarr[j]) mem[i][j] = true;
			else
				mem[i][j] = false;
		}
	}
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if ((ans[i] != 0 && ans[i] >ans[i - 1] + 1) || ans[i] == 0)
			ans[i] = ans[i - 1] + 1;

		for (int j = i + 1; j < N; j++) {
			if (mem[i][j] != 0)
			{
				if ((ans[j] != 0 && ans[j] >ans[i - 1] + 1) || ans[j] == 0)
					ans[j] = ans[i - 1] + 1;
			}
		}

	}

	cout << ans[N-1];
}

/*int pel(int left, int right) {
	int ans1 = 2600;
	int ans2 = 2600;
	int lidx = left;
	int ridx = right;
	char A = strarr[lidx];
	char B = strarr[ridx];
	if (lidx == ridx) {
		return 1;
	}
	if (A == B) {
		while (A == B && lidx < ridx) {
			A = strarr[++lidx];
			B = strarr[--ridx];
			
		}
		if (lidx == ridx || lidx > ridx) {
			return 1;
		}
		else {
			lidx = left;
			ridx = right;
			A = strarr[lidx];
			B = strarr[ridx];
		}
	}
		for (int i = lidx +1; i <= ridx; i++) {
			if (strarr[i] == strarr[ridx] && strarr[i-1] != strarr[i]) {
				int tmp;
				tmp = pel(i, ridx) + pel(lidx, i - 1);
				ans1 = min(ans1, tmp);
				break;
			}
		}
		for (int i = ridx - 1; i >= lidx; i--) {
			if (strarr[i] == strarr[lidx] && strarr[i + 1] != strarr[i]) {
				int tmp;
				tmp = pel(lidx, i) + pel(i + 1, ridx);
				ans2 = min(ans2, tmp);
				break;
			}
		}
		int ans = min(ans1, ans2);
		return ans;
		}*/