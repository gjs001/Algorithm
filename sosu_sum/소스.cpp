#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

#define Sn 186
int prevdata[100];
int sosu[500];
int sArr[1121];
int mem[15][1121];
int visit[1121];
int aArr[Sn];
int cnt;
int test[1000][3];
int sosu_sum(int n, int k, int prev, int *prevdata, int ok) { // �μ��� ���� ���� �����ϴ� �迭�� �־ ��� ����� ���� ����� �� �ִ�.
	if (k == 2 && n == 5) {									// �� ����� Ʋ�� ����̴�. �ֳ��ϸ� ���� �ܰ� ä�������� ��ƴ���� ����� �� ���� ������ �޸������̼��� �Ұ����ϴ�.
		                                                   // �������100 / 5����  2 3 13 ���� 80�� 2 5 11 ���� 80�� ���� �ι� ����ؾ������� �̸� �����ؼ� �޸������̼��� �� �� ����.
		//cout << "checkpoint2";
	}
	if (mem[k][n] != -1 && k < 2) {

		return mem[k][n];
	}
	if (n == 1 || n == 0) return 0;
	else if (k == 1) {
		if (sArr[n] == false && sosu[prev] < n) {
			for (int i = 0; i < ok-1; i++) {
				printf("%d-", prevdata[i]);
			}
			printf("%d", n);

			
			cout << endl;
			return  mem[k][n] = 1;
		}
		else{
			return  0;
		}

	}
	else {
		int ans = 0;
		int tmp = 0;
		for (int i = prev+1; i < Sn; i++) {
			if (prevdata[0] == 2 && prevdata[1] == 5 && prevdata[2] == 7) {
			//	cout << "check";
				cnt++;
			
			}
			if (n - sosu[i] <= 0) break;
			if (visit[sosu[i]] == true || sosu[i] == n - sosu[i]) continue; 
			if (visit[n - sosu[i]] == true) continue;
			prevdata[ok - k] = sosu[i];
			ans += sosu_sum(n - sosu[i], k - 1,i,prevdata,ok);



		}
		

		
		return mem[k][n] = ans;
	}
}



int main(){
	
	int cnt = 0;
	for (int i = 2; i <= 1120; i++) {
		if (sArr[i] == 1) continue;
		sosu[cnt++] = i;
		for (int j = i * 2; j <= 1120; j += i) {
			sArr[j] = 1;
		}
	}

	int T;
	cin >> T;
	mem[0][0] = 1;
	for (int i = 0; i <= Sn; i++) {
		for (int j = 1120; j >=	sosu[i];j-- ) {
			for (int k = 1; k <= 14; k++) {
				mem[k][j] += mem[k-1][j - sosu[i]];
			}
		}
	}


	for (int i = 0; i < T; i++) {
		int tmpN, tmpK;
		scanf("%d %d", &tmpN, &tmpK);
		aArr[i] = mem[tmpK][tmpN];
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", aArr[i]);
	}

}
