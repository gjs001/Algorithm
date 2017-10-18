#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1e9+7;
#define dif(x) (x+10)%10
using namespace std;
int turn[10] = { 0,1,1,1,2,2,2,1,1,1 };
//차이값이 인덱스 일때 돌리기 위해 필요한 수

//cache[i][j][k] : i=현재 인덱스, i인덱스가 j만큼 돌고 i+1이 k만큼 돌았을 때
//diff[i] : i인덱스, 목표값과 원래값의 차이값을 저장해둔 배열
//n : 자물쇠 길이
//t : temp
int cache[102][10][10], diff[102], n, t;

//curr : 현재인덱스
//c_turn : 현재인덱스가 돌아간 횟수
//n_turn : 다음인덱스가 돌아간 횟수
int dfs(int curr, int c_turn, int n_turn) {
	if (curr == n) return 0;
	int &ret = cache[curr][c_turn][n_turn];
	if (ret != -1) return ret;
	ret = INF;
	//t_now : 현재인덱스에서 돌려야 하는 횟수
	int t_now = dif(diff[curr] + c_turn);
	//모든 경우(100번) 다돌려본다.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			//cost : 다음인덱스를 현재 돌아간 것에 i+j번 더돌린 것
			int cost = turn[i] + turn[j] + turn[dif(t_now + i + j)];
			if (cost < 3)//3번이상이면 반복하는 것이나 다름없으므로
						 //완탐 dfs(다음인덱스, 다음인덱스 돌아간 횟수에 i+j번, i번 돌림) + 현재 인덱스에서 든 cost)
				ret = min(ret, dfs(curr + 1, dif(n_turn + i + j), i) + cost);
		}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %1d", &diff[i]);
	for (int i = 0; i < n; i++)
		scanf(" %1d", &t), diff[i] = dif(diff[i] - t);
	printf("%d", dfs(0, 0, 0));
}