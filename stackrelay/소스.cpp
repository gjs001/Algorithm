#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>


using namespace std;


int stackarr[200002];
int size, cur, cnt;
char ans[200002];
int flag;
int qArr[100001];

void push(int data) {
	stackarr[cur++] = data;
	ans[cnt++] = '+';

}
void pop() {
	stackarr[cur--] = 0;
	ans[cnt++] = '-';
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i<N; i++) {
		scanf("%d", &qArr[i]);
	}
	int size = 0;
	int qcnt = 0;
	while (cur || size < N) {
		if (qArr[qcnt] > size) {
			push(++size);
		}
		else if (qArr[qcnt] <= size) {
			if (qArr[qcnt] == stackarr[cur - 1]) {
				pop();
				qcnt++;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag) break;


	}

	if (flag) printf("NO");
	else {
		for (int i = 0; i<cnt; i++)
			printf("%c\n", ans[i]);
	}
}