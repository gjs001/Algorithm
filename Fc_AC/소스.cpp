#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;


int T, N;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {

		
		deque<int> A;
		char fcc[100001];
		char qArr[100001];
		int x = 0;
		int cnt = 0;
		bool flag = false;
		bool errorflag = false;
		scanf("%s\n%d", &fcc, &N);
		while (1)
		{
			char c = getchar();
			if (c == ']')
			{
				if (x != 0) A.push_back(x);
				break;
			}
			else if (c >= '0' && c <= '9') x = x * 10 + c - '0';
			else if (c == ',') { A.push_back(x); x = 0; }
		}


		
		for (int j = 0; j < strlen(fcc); j++) {
			if (fcc[j] == 'R') flag = !flag;
			else if (fcc[j] == 'D' && A.empty()) {
				printf("error\n");
				errorflag = true;
				break;
			}
			else if (fcc[j] == 'D' && !flag) {
				A.pop_front();
			}
			else {
				A.pop_back();
			}

		}
		if (errorflag) continue;
		cout << '[';
		if (!flag) {
			while (A.size()) {
				int tmp = A.front();
				A.pop_front();
				printf("%d", tmp);
				if (A.size()) printf(",");
			}

		}
		else {
			while (A.size()) {
				int tmp = A.back();
				A.pop_back();
				printf("%d", tmp);
				if (A.size()) printf(",");
			}
		}
		cout << "]\n";
	}
}