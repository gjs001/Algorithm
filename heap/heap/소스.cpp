#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define lchild(dis) 2*dis+1
#define rchild(dis) 2*dis+2
#define parent(dis) (dis-1)/2
#define INF 987654321
int N;
/*

// stl을 사용한 heap정렬
int main() {
	cin >> N;
	
	priority_queue<int,vector<int>,greater<int>> heap;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		heap.push(tmp);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", heap.top());
		heap.pop();
	}

}*/

int sortarr[2000002];

class heap {
public:
	int size;
	heap() {
		size = 0;
	}

	void swap(int a, int b) {
		int tmp;
		tmp = sortarr[a];
		sortarr[a] = sortarr[b];
		sortarr[b] = tmp;
	}
	void push(int data) {
		int now = size++;
		sortarr[now] = data;
		if (size == 1) { return; }
		while (1)
		{
			if (now > 0 && sortarr[now] < sortarr[parent(now)]) {
				swap(now, parent(now));
				now = parent(now);
			}
			else if (lchild(now) < size && sortarr[now] > sortarr[lchild(now)]) {
				swap(now, lchild(now));
				now = lchild(now);
			}
			else if (rchild(now) < size && sortarr[now] > sortarr[rchild(now)]) {
				swap(now, rchild(now));
				now = rchild(now);
			}		

			else {
				return;
			}

		}
	}
	int pop() {
		int popdata = sortarr[0];
		sortarr[0] = sortarr[--size];
		sortarr[size] = INF;
		int smallchild;
		if (sortarr[lchild(0)] > sortarr[rchild(0)]) {
			smallchild = rchild(0);
		}
		else smallchild = lchild(0);
		int now = 0;
		while (1) {
 			if (sortarr[smallchild] < sortarr[now]) {
				swap(smallchild, now);
				now = smallchild;
			}
			else break;
			
			if (sortarr[lchild(now)] > sortarr[rchild(now)]) {
				smallchild = rchild(now);
			}
			else smallchild = lchild(now);
		}
		return popdata;
	}
};

int main() {
	cin >> N;
	heap newheap;
	int tmp;
	for (int i = 0; i <= rchild(N); i++) {
		sortarr[i] = INF;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		newheap.push(tmp);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", newheap.pop());
		
	}
}