#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>


using namespace std;

stack<int> a;


int main() {
	

	int ans = 0;
	char iron[100000];

	cin >> iron;

	for (int i = 0; i < 100000; i++) {
		if (iron[i] == NULL) break;
		if (iron[i] == '(') a.push(1);
		else if (iron[i] == ')') {
			if(iron[i-1] == '(') ans += a.size() - 1;
			else ans += 1;

			a.pop();
		}
	}

	cout << ans;




}