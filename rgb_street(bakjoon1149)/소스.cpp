#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define min(a,b) ((a) <(b) ? (a):(b))

#define red 1
#define green 2
#define blue 3

int N;
int mem[1001][4];
int dp[1001][4];
int pt(int n,int prev) {
	int ans;

	if (!dp[n][green]) {
		if (n == 1) dp[1][green] = mem[1][green];
		else dp[n][green] = pt(n - 1, green) + mem[n][green];
	}
	if (!dp[n][blue]) {
		if (n == 1) dp[1][blue] = mem[1][blue];
		else dp[n][blue] = pt(n - 1, blue) + mem[n][blue];
	}
	if (!dp[n][red]) {
		if (n == 1) dp[1][red] = mem[1][red];
		else dp[n][red] = pt(n - 1, red) + mem[n][red];
	}

	if(prev == red)	return ans = min(dp[n][green], dp[n][blue]);
	else if(prev == green) return ans = min(dp[n][red], dp[n][blue]);
	else if(prev == blue) return ans = min(dp[n][red], dp[n][green]);
	else {
		ans = min(dp[n][green], dp[n][blue]);
		return ans = min(ans, dp[n][red]);
		
	}
}


int main(){

	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &mem[i][red], &mem[i][green], &mem[i][blue]);
	}
	cout << pt(N, 0);


}
