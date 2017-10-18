#include <stdio.h>
// 1. 사이즈가 50인 큐를 배열로 구현
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

// 2. 사이즈가 50인 스택을 배열로 구현
int stack[50]; 
int stack_top = -1;

void stack_push(int data) {
	stack[++stack_top] = data;
}

int stack_pop() {
	if (stack_top < 0) return -1;
	return	stack[stack_top--];
}

// 참고. swap 함수 구현 
void swap(int& a, int& b) { //참조변수(혹은 레퍼런스 변수)를 이용한 swap함수
	int tmp = a; // 참조변수란 일반 변수나 배열, 객체들의 주소값을 가지는 변수이다. 쉽게 말하면 포인터같은 놈인데 표현은 일반 변수로 한다고 생각하면 됩니다.
	a = b;		// 참조변수 대신 포인터가 편하시면 포인터를 사용하셔도 됩니다.
	b = tmp;
	return;
}

// 3. 선택정렬 ※ 시간복잡도 O(n^2)
void selection_sort_ASC(int target[], int size) { // 오름차순 선택정렬 : 정렬되지 않은 배열에서 가장 작은 값을 가장 왼쪽으로 그 다음 작은 값들을 오른쪽으로 한칸씩 이동하면서 바꿔주면서 정렬하는 방법
		int INF = 987654321; // 이 정렬을 사용할 배열의 값으로는 절대 나오지 않을만큼 큰 값(보통 987654321, int 최대 범위 근처인 20억 그리고 가끔 long long 최대범위의 근처인 900경정도 사용)
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

void selection_sort_DE(int target[], int size) { // 내림차순 선택정렬 : 배열의 뒤에서 부터 오름차순으로 정렬해주면 내림차순으로 정렬한 배열이 된다. or 그냥 비교해서 큰 값부터 앞으로 넣어도 OK
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


// 4. 삽입 정렬 ※ 시간복잡도 O(n^2)
void insertion_sort(int target[], int size, int order) { // 앞에서부터 정렬해나가는 방법으로 임의의 i번째에 있는 값을 정렬할 때는 0~i-1항의 값들은 정렬이 되어있는 상태입니다.
														// 따라서 i-1부터 0까지의 값과 i번째 값을 비교하면서 i번째 값이 있어야되는 위치를 찾습니다.
	for (int i = 1; i < size; i++) { // 배열의 2번째 항부터
		int cur = i;
		for (int j = i - 1 ; j >= 0; j--) {
			if (order == 1 && target[j] > target[cur]) swap(target[j], target[cur--]); // 오름차순일 경우
			if (order == 0 && target[j] < target[cur]) swap(target[j], target[cur--]); // 내림차순일 경우
		}

	}
}

// 5. 피보나치 값 구하기 (top-down 방식 : i번째 값을 구하기 위해서 i-1번째 값을 구하고를 반복하는 방법 개념상 위에서 아래로 내려간다, 주로 재귀함수를 사용)
int fibonacci_td(int index) { // index번째 피보나치 값을 구하는 함수
	if (index <= 1) return index;
	return fibonacci_td(index - 1) + fibonacci_td(index - 2);
}

// 5_2. 피보나치 값 구하기 (bottom_up 방식 : i번째 값을 구하기 위해서 0번째 값부터 구하면서 위로 올라가는 방법,주로 반복문(for,while)을 사용)
int fibonacci_bu(int index) { // index번째 피보나치 값을 구하는 함수
	int dp[1000];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= index; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[index];
}


// 6. tree순회

int Tree[1 << 10]; // 2^10승짜리 이진트리를 담을 배열 선언
int Tree_visit[1 << 10]; // 해당 노드가 사용중인지 확인하는 배열, 미사용이면 0, 사용중이면 1
#define leftchild(n) (2*n+1) // 왼쪽 자식의 위치는 자기 index의 2를 곱한 다음 1을 더한 곳이다.
#define rightchild(n) (2*n+2) // 오른쪽 자식의 위치는 왼쪽 자식의 위치에 1을 더한 곳이다.

void add_tree(int data) { // 트리 추가
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

// 전위순회

void pre_order(int cur) {
	if (Tree_visit[cur] == 1) {
		printf("%d ", Tree[cur]); // 전위순회는 재귀문 앞(전)에 자신의 값을 출력한다.
		pre_order(leftchild(cur));
		pre_order(rightchild(cur));
	}
}
// 중위 순회

void in_order(int cur) {
	if (Tree_visit[cur] == 1) {
		in_order(leftchild(cur));
		printf("%d ", Tree[cur]); // 중위순회는 재귀문 중간에 자신의 값을 출력한다.
		in_order(rightchild(cur));
	}
}

// 후위 순회
void post_order(int cur) {
	if (Tree_visit[cur] == 1) {
		post_order(leftchild(cur));
		post_order(rightchild(cur));
		printf("%d ", Tree[cur]); // 후위순회는 재귀문 후에 자신의 값을 출력한다.
	}
}

int main() {
	que_push(1);
	que_push(5);
	que_push(7);
	for (int i = 0; i < 3; i++) printf("%d ", que_pop()); //큐 테스트

	printf("\n");
	stack_push(1);
	stack_push(5);
	stack_push(7);
	for (int i = 0; i < 3; i++) printf("%d ", stack_pop()); //스택 테스트
	printf("\n");

	// 선택정렬 테스트
	int A_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };
	int B_list[] = { 7, 6, 2, 11, 3, 4, 5,6,1,3 };

	selection_sort_ASC(A_list, 10);
	selection_sort_DE(B_list, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", A_list[i]);
	}
	printf("\n");

	// 삽입정렬 테스트
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
	
	// 피보나치 테스트
	printf("%d\n", fibonacci_bu(20));
	printf("%d\n", fibonacci_td(20));

	// 트리테스트

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