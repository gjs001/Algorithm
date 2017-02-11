
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

typedef struct A{ // ���������� ��� sort�� ���ϰ� �ϱ����� ����ü ���� 
	char name[11]; int kuk; int young; int su; // string�� ������� �ʰ� char �迭�� ������� �� �ҿ�ð� ���� (108ms -> 64ms)
}A;




bool cmp(const A &C1, const A &C2) { 
	if (C1.kuk != C2.kuk) return (C1.kuk > C2.kuk);
	if (C1.young != C2.young) return (C1.young < C2.young);
	if (C1.su != C2.su) return (C1.su > C2.su);
	for (int i = 0; i < strlen(C1.name); i++) {
		if (C1.name[i] != C2.name[i]) return C1.name[i] < C2.name[i];
	} // = strcmp�� �ҿ�ð��� ���� ����.(���� ����Ʈ ���� ���Ͻð�)
	
}



int main() {
	int N;
	cin >> N;
	
	A Clist[10000]; // vector ������� �ʰ� ����ü �迭 ���� �Ͽ��� �� �ҿ�ð� ����(136ms -> 108ms)

	for (int i = 0; i < N; i++) {
	

		 scanf("%s %d %d %d", Clist[i].name, &Clist[i].kuk, &Clist[i].young, &Clist[i].su);
				
	}



	stable_sort(Clist, Clist+N, cmp); //stable_sort�� ������ sort�Լ��� ����� ��� ���� �� ��ġ�� �����Ѵ�. 

	for (int i = 0; i < N; i++) {
		printf("%s\n", Clist[i].name); 
	}

}
