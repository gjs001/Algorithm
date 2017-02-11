#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef struct k {
	int num;
	char c;
}k;

string qArr;
stack<k> A;

int stack_cal() {

	int size = qArr.size();

	for (int i = 0; i < size; i++) {
		int prev = 0;
		if (qArr[i] == '(' || qArr[i] == '[') {
			k tmp;
			tmp.c = qArr[i];
			A.push(tmp);
		}
		else {

			if (qArr[i] == ')') {
				while (A.size()) {
					if (A.top().c != 'n' && A.top().c != '(') {
						return 0;
					}
					else if (A.top().c == '(') {
						A.top().c = 'n';
						if (prev == 0) prev = 1;
						A.top().num = prev * 2;
						break;
					}
					prev += A.top().num;
					A.pop();
				}
			}
			if (qArr[i] == ']') {
				while (A.size()) {
					if (A.top().c != 'n' && A.top().c != '[') {
						return 0;
					}
					else if (A.top().c == '[') {
						A.top().c = 'n';
						if (prev == 0) prev = 1;
						A.top().num = prev * 3;
						break;
					}
					prev += A.top().num;
					A.pop();
				}
			}
		}
	}
	int ans = 0;
	size = A.size();
	for (int i = 0; i < size; i++) {
		if (A.top().c != 'n') return 0;
		ans += A.top().num;
		A.pop();
	}
	return ans;
}

int main() {
	cin >> qArr;
	int ans = stack_cal();
	cout << ans;
}