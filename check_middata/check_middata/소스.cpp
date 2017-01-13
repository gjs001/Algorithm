#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment( lib , "winmm.lib" )

#define lchild(dis) 2*dis+1
#define rchild(dis) 2*dis+2
#define parent(dis) (dis-1)/2
#define MAX 131072
using namespace std;
int N;
int K;
int sArr[250001];
int segment_Tree[MAX * 2];

long long ans;


void add_num(int value, int* Tree) {
	int idx = value + MAX;
	while (idx) {
		Tree[idx]++;
		idx = parent(idx);
	}
	Tree[0]++;
}

void remove_num(int value, int *Tree) {
	int idx = value + MAX;
	while (idx) {
		Tree[idx]--;
		idx = parent(idx);
	}
	Tree[0]--;
}

int median(int * Tree) {
	int med = ((K + 1) / 2) ;
	int idx = 0;
	while (idx < MAX) {
		if (med <= Tree[lchild(idx)]) {
			idx = lchild(idx);
		}
		else {
			med -= Tree[lchild(idx)];
			idx = rchild(idx);
		}
	}
	return idx - MAX;
}


void check_data() {
	

	for (int i = 0; i < N; i++) { // 약 31 * count 최대 735만번
		add_num(sArr[i], segment_Tree);
		if (i > K - 1) {
			remove_num(sArr[i - K], segment_Tree);
		}
		if (i >= K - 1) {
			ans += median(segment_Tree);
		}


	}
}

int main() {

	cin >> N >> K;

	//for (int i = 0; i < N; i++) {
	//	sArr[i] = 100000 % (rand()+1);
	//}
	for (int i = 0; i < N; i++) {
	scanf("%d", &sArr[i]);
	}
	int starttime = timeGetTime();

//	for (int i = 0; i < N; i++) {
//		if (sArr[i] == 5868) cout << i << endl;
//	}
	check_data();
	
	printf("%lld\n", ans);
	cout << timeGetTime() - starttime; //250ms정도 걸리는데~ 왜틀리지?
	
}



/*
int del_number(int target, int left, int right) {
int mid = (left + right) /2;
if (kArr[mid] == target) return mid;
else if (kArr[mid] > target) return del_number(target, left, mid);
else return del_number(target, mid + 1, right);

}
int add_number(int target, int left, int right) {
int mid = (left + right) / 2;
if (left == right) {
if (kArr[left] > target)
return left;
else
return left+1;

}
if (kArr[mid] == target) { return mid; }
else if (kArr[mid] > target) return add_number(target, left, mid);
else return add_number(target, mid + 1, right);

}

void renew_Arr(int del, int add) {
int mid = kArr[((K + 1) / 2) - 1];

int delidx = del_number(del, 0, K - 1); // logK 5000기준 12~13;
if(delidx != K - 1)memcpy(&kArr[delidx], &kArr[delidx+1], sizeof(int)*(K-(delidx +1)));
kArr[K - 1] = 0;
int addidx = 0;
if(K > 1)addidx = add_number(add, 0, K - 2); // 12 ~ 13
if(addidx != K - 1 )memcpy(&kArr[addidx+1], &kArr[addidx], sizeof(int)*(K - (addidx + 1)));
kArr[addidx] = add; //1
}



void check_data() {
int count = N - K + 1;

for (int i = 0; i < K; i++) {
kArr[i] = sArr[i];
}
sort(kArr,kArr+K); //최대 5000*13
ans += kArr[((K + 1) / 2) - 1];
int cnt = 0;
int *tmp = new int[K];
for (int i = 1; i < count; i++) { // 약 31 * count 최대 735만번
renew_Arr(sArr[i - 1], sArr[K + i -1]);
ans += kArr[((K + 1) / 2) - 1]; //1

}
delete[] tmp;
}*/