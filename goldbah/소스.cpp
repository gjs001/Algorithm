#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;


int N;

int sosu[5000]; // �Ҽ��� ���ڵ��� �����ϱ� ���� �迭
bool cArr[10001]; // idx�� �ش��ϴ� ���� �Ҽ��̸� false �Ҽ��� �ƴϸ� true
int tArr[10000]; // ������ testcase���� ���ִ� �迭


int main() {

	cin >> N; // �Էº�
	for (int i = 0; i < N; i++) {
		scanf("%d", &tArr[i]);
	}

	int cnt = 0;

	for (int i = 2; i <= 10000; i++) { //���� 4~10000������ �Ҽ��� ���ؼ� sosu[]�� �����Ѵ�.
		if (cArr[i] == true) continue;
		sosu[cnt++] = i;
		for (int j = i*2; j <= 10000; j += i) {
			cArr[j] = true;
		}
	}
	
	for (int i = 0; i < N; i++) { 
		int gap = 10000;
		int gidx = 0;
		for (int j = 0; j < cnt; j++) { // tArr�� ����� testcase ���� ����� �Ҽ��� �� ���� ��
			int tmp = tArr[i] - sosu[j];
			if (cArr[tmp] == false) {//testcase - sosu[]�� �Ҽ��� ��� 
				if (sosu[j] >= tmp) { // �� �Ҽ����� ���̸� ������ ���̰� ���� ���� ���� �Ҽ����� ã�´�.

					if (gap > (sosu[j] - tmp)) { // ������ ������ �ȵǴ� ���ǹ����� Ȯ���ϰ� �� ���� ����� ���
						gap = sosu[j] - tmp;
						gidx = j; 
					}
				}
				else {

					if (gap > (tmp - sosu[j])) { 
						gap = tmp - sosu[j];
						gidx = j;
					}
				}
				
			}
		}
		if((tArr[i] - sosu[gidx]) > tArr[i]/2)	printf("%d %d\n",sosu[gidx],tArr[i] - sosu[gidx]); // �� �Ҽ� �߿��� �׻� ���� ���� ���� ��µǾ�� �Ѵ�.
		else printf("%d %d\n", tArr[i] - sosu[gidx], sosu[gidx]);
	}
}