#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int M, N;
bool fArr[1000001]; // idx ���� �ش��ϴ� ���� �Ҽ��̸� false �ƴϸ� true


int main() {
	vector<int> a; // �󸶳� �Է��� ���� ������ ��õǾ����� �ʾƼ� ���͸� Ȱ��

	while (1) { // 0�� ���� �� ���� ��� �Է��� �޴´�.
		int tmp = 0;
		scanf("%d", &tmp);
		if (tmp == 0) break;
		else a.push_back(tmp);
	}
		
		
	for (int k = 0; k < a.size(); k++) { // �����佺�׳׽��� ü����
		int cnt = 0;
		for (int i = 2; i <= a[k]*2; i++) { //����Ʈ�� ������ n���� ũ�� 2*n���� ���� ���� ���ϴ� �����̹Ƿ� range�� �ƽø��� 2*n
			if (fArr[i] == true) continue;
			if (i > a[k]) cnt++; // �̴ϸ��� n;
			for (int j = i * 2; j <= a[k]*2; j += i) { //ü�� �ɷ�����
				fArr[j] = true;
			}

		}
		for (int i = 0; i < a[k] * 2; i++) fArr[i] = false; //������ ���ؾ��ϴ� fArr[] �ʱ�ȭ�� ������
		printf("%d\n", cnt); //������ �Ҽ� ������ ���
	}

}