#include <stdio.h>
// 1. ����� 50�� ť�� �迭�� ����
int que[50]; 
int que_front = 0;
int que_rear = 0;

void que_push(int data) {
	que[que_rear++] = data; 
}

int que_pop() {
	if (que_rear == que_front) return -1;
	return que[que_front++];
}

// 2. ����� 50�� ������ �迭�� ����
int stack[50]; 
int stack_top = -1;

void stack_push(int data) {
	stack[++stack_top] = data;
}

int stack_pop() {
	if (stack_top < 0) return -1;
	return	stack[stack_top--];
}

// ����. swap �Լ� ���� 
void swap(int& a, int& b) { //��������(Ȥ�� ���۷��� ����)�� �̿��� swap�Լ�
	int tmp = a; // ���������� �Ϲ� ������ �迭, ��ü���� �ּҰ��� ������ �����̴�. ���� ���ϸ� �����Ͱ��� ���ε� ǥ���� �Ϲ� ������ �Ѵٰ� �����ϸ� �˴ϴ�.
	a = b;		// �������� ��� �����Ͱ� ���Ͻø� �����͸� ����ϼŵ� �˴ϴ�.
	b = tmp;
	return;
}

// 3. �������� �� �ð����⵵ O(n^2)
void selection_sort_ASC(int target[], int size) { // �������� �������� : ���ĵ��� ���� �迭���� ���� ���� ���� ���� �������� �� ���� ���� ������ ���������� ��ĭ�� �̵��ϸ鼭 �ٲ��ָ鼭 �����ϴ� ���
		int INF = 987654321; // �� ������ ����� �迭�� �����δ� ���� ������ ������ŭ ū ��(���� 987654321, int �ִ� ���� ��ó�� 20�� �׸��� ���� long long �ִ������ ��ó�� 900������ ���)
		for (int i = 0; i < size; i++) {
			int min_Data = INF;
			int min_index = 0;
			for (int j = i; j < size; j++) {
				if (min_Data > target[j]) {
					min_Data = target[j];
					min_index = j;
				}
			}
			swap(target[i], target[min_index]);
		}
}

void selection_sort_DE(int target[], int size) { // �������� �������� : �迭�� �ڿ��� ���� ������������ �������ָ� ������������ ������ �迭�� �ȴ�. or �׳� ���ؼ� ū ������ ������ �־ OK
	int INF = 987654321; 
	for (int i = size; i >= 0; i--) { 
		int min_Data = INF;
		int min_index = 0;
		for (int j = i; j >= 0; j--) {
			if (min_Data > target[j]) {
				min_Data = target[j];
				min_index = j;
			}
		}
		swap(target[i], target[min_index]);
	}
}


// 4. ���� ���� �� �ð����⵵ O(n^2)
void insertion_sort(int target[], int size, int order) { // �տ������� �����س����� ������� ������ i��°�� �ִ� ���� ������ ���� 0~i-1���� ������ ������ �Ǿ��ִ� �����Դϴ�.
														// ���� i-1���� 0������ ���� i��° ���� ���ϸ鼭 i��° ���� �־�ߵǴ� ��ġ�� ã���ϴ�.
	for (int i = 1; i < size; i++) { // �迭�� 2��° �׺���
		int cur = i;
		for (int j = i - 1 ; j >= 0; j--) {
			if (order == 1 && target[j] > target[cur]) swap(target[j], target[cur--]); // ���������� ���
			if (order == 0 && target[j] < target[cur]) swap(target[j], target[cur--]); // ���������� ���
		}

	}
}

// 5. �Ǻ���ġ �� ���ϱ� (top-down ��� : i��° ���� ���ϱ� ���ؼ� i-1��° ���� ���ϰ� �ݺ��ϴ� ��� ����� ������ �Ʒ��� ��������, �ַ� ����Լ��� ���)
int fibonacci_td(int index) { // index��° �Ǻ���ġ ���� ���ϴ� �Լ�
	if (index <= 1) return index;
	return fibonacci_td(index - 1) + fibonacci_td(index - 2);
}

// 5_2. �Ǻ���ġ �� ���ϱ� (bottom_up ��� : i��° ���� ���ϱ� ���ؼ� 0��° ������ ���ϸ鼭 ���� �ö󰡴� ���,�ַ� �ݺ���(for,while)�� ���)
int fibonacci_bu(int index) { // index��° �Ǻ���ġ ���� ���ϴ� �Լ�
	int dp[1000];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= index; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[index];
}


// 6. tree��ȸ

int Tree[1 << 10]; // 2^10��¥�� ����Ʈ���� ���� �迭 ����
int Tree_visit[1 << 10]; // �ش� ��尡 ��������� Ȯ���ϴ� �迭, �̻���̸� 0, ������̸� 1
#define leftchild(n) (2*n+1) // ���� �ڽ��� ��ġ�� �ڱ� index�� 2�� ���� ���� 1�� ���� ���̴�.
#define rightchild(n) (2*n+2) // ������ �ڽ��� ��ġ�� ���� �ڽ��� ��ġ�� 1�� ���� ���̴�.

void add_tree(int data) { // Ʈ�� �߰�
	int cur = 0;
	if (Tree_visit[0] == 0) {
		Tree[0] = data;
		Tree_visit[0] = 1;
		return;
	}
	while (1) {
		if (Tree[cur] > data) {
			cur = leftchild(cur);
		}
		else{
			cur = rightchild(cur);
		}

		if (Tree_visit[cur] == 0) {
			Tree[cur] = data;
			Tree_visit[cur] = 1;
			return;
		}
	}
}

// ������ȸ

void pre_order(int cur) {
	if (Tree_visit[cur] == 1) {
		printf("%d ", Tree[cur]); // ������ȸ�� ��͹� ��(��)�� �ڽ��� ���� ����Ѵ�.
		pre_order(leftchild(cur));
		pre_order(rightchild(cur));
	}
}
// ���� ��ȸ

void in_order(int cur) {
	if (Tree_visit[cur] == 1) {
		in_order(leftchild(cur));
		printf("%d ", Tree[cur]); // ������ȸ�� ��͹� �߰��� �ڽ��� ���� ����Ѵ�.
		in_order(rightchild(cur));
	}
}

// ���� ��ȸ
void post_order(int cur) {
	if (Tree_visit[cur] == 1) {
		post_order(leftchild(cur));
		post_order(rightchild(cur));
		printf("%d ", Tree[cur]); // ������ȸ�� ��͹� �Ŀ� �ڽ��� ���� ����Ѵ�.
	}
}

int main() {
	que_push(1);
	que_push(5);
	que_push(7);
	for (int i = 0; i < 3; i++) printf("%d ", que_pop()); //ť �׽�Ʈ

	printf("\n");
	stack_push(1);
	stack_push(5);
	stack_push(7);
	for (int i = 0; i < 3; i++) printf("%d ", stack_pop()); //���� �׽�Ʈ
	printf("\n");

	// �������� �׽�Ʈ
	int A_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };
	int B_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };

	selection_sort_ASC(A_list, 10);
	selection_sort_DE(B_list, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", A_list[i]);
	}
	printf("\n");

	// �������� �׽�Ʈ
	for (int i = 0; i < 10; i++) {
		printf("%d ", B_list[i]);
	}
	printf("\n");

	int C_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };
	int D_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };
	insertion_sort(C_list, 10,1);
	insertion_sort(D_list, 10, 0);
	for (int i = 0; i < 10; i++) {
		printf("%d ", C_list[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", D_list[i]);
	}
	printf("\n");
	
	// �Ǻ���ġ �׽�Ʈ
	printf("%d\n", fibonacci_bu(20));
	printf("%d\n", fibonacci_td(20));

	// Ʈ���׽�Ʈ

	add_tree(5);
	add_tree(2);
	add_tree(7);
	add_tree(1);
	add_tree(3);
	add_tree(6);
	add_tree(9);
	add_tree(4);
	add_tree(8);
	add_tree(10);

	pre_order(0);
	printf("\n");
	in_order(0);
	printf("\n");
	post_order(0);
	printf("\n");
}