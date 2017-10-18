#include <iostream>


using namespace std;

// 3. 배열로 구현한 max-heap
#define left(a) (2*a)
#define right(a) (2*a+1)
#define parent(a) (a/2)
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

int heap_arr[1 << 12];
int heap_size;

void heap_push(int data) {
	int cur;
	heap_arr[++heap_size] = data;
	cur = heap_size;
	while (cur != 1 || heap_arr[parent(cur)] < heap_arr[cur]) {
		swap(heap_arr[cur], heap_arr[parent(cur)]);
		cur = parent(cur);
	}
	return;
}

int heap_pop() {
	if (heap_size == 0) return -1;
	if (heap_size == 1) {
		return heap_arr[heap_size--];
	}
	int tmp = heap_arr[1];
	heap_arr[1] = NULL;
	swap(heap_arr[1], heap_arr[heap_size]);
	heap_size--;
	int cur = 1;
	while (1) {
		if(heap_arr[left(cur)] < heap_arr[cur])
	}
	

}

