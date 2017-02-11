#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>

using namespace std;

deque<int> A;
int qArr[50];
int ans;

void leftmove(){
	A.push_back(A.front());
	A.pop_front();
}

void rightmove() {
	A.push_front(A.back());
	A.pop_back();
}

int Lsearch(int target) {
	int lcnt = 0;

	while (!(A.front() == target)) {
		leftmove();
		lcnt++;
	}
	for (int i = 0; i < lcnt; i++) {
		rightmove();
	}
	return lcnt;

}
int Rsearch(int target) {
	int rcnt = 0;
	while (!(A.front() == target)) {
		rightmove();
		rcnt++;
	}
	for (int i = 0; i < rcnt; i++) {
		leftmove();
	}
	return rcnt;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		A.push_back(i+1);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d",&qArr[i]);
	}
	int cur = 1;
	for (int i = 0; i < M; i++) {
		cur = A.front();
		int target = qArr[i];
		int rcnt = Rsearch(target);
		int lcnt = Lsearch(target);
		if (rcnt <= lcnt) {
			for (int j = 0; j < rcnt; j++) {
				rightmove();
				ans++;
			}
			A.pop_front();
		}
		else {
			for (int j = 0; j < lcnt; j++) {
				leftmove();
				ans++;
			}
			A.pop_front();
		}
	}
	cout << ans;
}