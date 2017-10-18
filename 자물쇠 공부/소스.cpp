#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1e9+7;
#define dif(x) (x+10)%10
using namespace std;
int turn[10] = { 0,1,1,1,2,2,2,1,1,1 };
//���̰��� �ε��� �϶� ������ ���� �ʿ��� ��

//cache[i][j][k] : i=���� �ε���, i�ε����� j��ŭ ���� i+1�� k��ŭ ������ ��
//diff[i] : i�ε���, ��ǥ���� �������� ���̰��� �����ص� �迭
//n : �ڹ��� ����
//t : temp
int cache[102][10][10], diff[102], n, t;

//curr : �����ε���
//c_turn : �����ε����� ���ư� Ƚ��
//n_turn : �����ε����� ���ư� Ƚ��
int dfs(int curr, int c_turn, int n_turn) {
	if (curr == n) return 0;
	int &ret = cache[curr][c_turn][n_turn];
	if (ret != -1) return ret;
	ret = INF;
	//t_now : �����ε������� ������ �ϴ� Ƚ��
	int t_now = dif(diff[curr] + c_turn);
	//��� ���(100��) �ٵ�������.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			//cost : �����ε����� ���� ���ư� �Ϳ� i+j�� ������ ��
			int cost = turn[i] + turn[j] + turn[dif(t_now + i + j)];
			if (cost < 3)//3���̻��̸� �ݺ��ϴ� ���̳� �ٸ������Ƿ�
						 //��Ž dfs(�����ε���, �����ε��� ���ư� Ƚ���� i+j��, i�� ����) + ���� �ε������� �� cost)
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