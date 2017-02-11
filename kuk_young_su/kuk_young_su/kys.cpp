
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

typedef struct A{ // 데이터형을 묶어서 sort를 편하게 하기위한 구조체 선언 
	char name[11]; int kuk; int young; int su; // string을 사용하지 않고 char 배열을 사용했을 때 소요시간 감소 (108ms -> 64ms)
}A;




bool cmp(const A &C1, const A &C2) { 
	if (C1.kuk != C2.kuk) return (C1.kuk > C2.kuk);
	if (C1.young != C2.young) return (C1.young < C2.young);
	if (C1.su != C2.su) return (C1.su > C2.su);
	for (int i = 0; i < strlen(C1.name); i++) {
		if (C1.name[i] != C2.name[i]) return C1.name[i] < C2.name[i];
	} // = strcmp와 소요시간은 거의 같다.(백준 사이트 기준 동일시간)
	
}



int main() {
	int N;
	cin >> N;
	
	A Clist[10000]; // vector 사용하지 않고 구조체 배열 선언 하였을 때 소요시간 감소(136ms -> 108ms)

	for (int i = 0; i < N; i++) {
	

		 scanf("%s %d %d %d", Clist[i].name, &Clist[i].kuk, &Clist[i].young, &Clist[i].su);
				
	}



	stable_sort(Clist, Clist+N, cmp); //stable_sort는 여러번 sort함수를 사용할 경우 정렬 전 위치를 보장한다. 

	for (int i = 0; i < N; i++) {
		printf("%s\n", Clist[i].name); 
	}

}
