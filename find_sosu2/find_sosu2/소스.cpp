#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
#define MAX 1048576
int M, N;
int fArr[1000001];
int ans[1000001];
#define nise_mono true
 queue<int> A;

int main() {
	cin >> M >> N;
	int size = 0;
	
	for (int i = 2; i <= N; i++) { //�ڱ⸻�� Ī���� ���� ȥ������ ã��
		if (fArr[i] == 1) continue;
		if (i >= M) printf("%d\n", i);
		int cNum = i;
		int cnt = 1;
		for(int j=i*2;j<=N;j +=i){ // ������ i ������ �ٽ� ����ȵǴϱ� i*2���� �����ؼ� i�� �����༭ i�� ��� ������ ��� �ϼ����� ���������
			fArr[j] = nise_mono;
		}
	}

}