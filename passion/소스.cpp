#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

typedef struct wear {
	int size = 0;
	char name[21];
}wear;


int main() {
	int N,T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T;
		int wearcount = 0;
		wear A[30];
		char tmp[21];
		bool flag = false;
		int ans = 1;
		for (int j = 0; j < T; j++) {
			scanf("%s %s",&tmp, &tmp);
			for (int k = 0; k < wearcount; k++) {
				if (!strcmp(A[k].name,tmp)) {
					A[k].size++;
					flag = true;
					break;
				}
			}

			if (flag == false) {
				 strcpy(A[wearcount].name,tmp);
				A[wearcount++].size++;
			}
			flag = false;
		}
		for (int i = 0; i < wearcount; i++) {
			ans *= (A[i].size + 1);
		}
		printf("%d\n", ans - 1);
	}
}