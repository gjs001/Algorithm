#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;



int main() {
	int N;
	deque<int> A;
	cin >> N;
	int ans[10001];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		char tmp[15];
		int data;
		scanf("%s", &tmp, &data);
		if (tmp[1] == 'u' && tmp[5] == 'b') {
			scanf("%d", &data);
			A.push_back(data);
		}
		else if (tmp[1] == 'u' && tmp[5] == 'f') {
			scanf("%d", &data);
			A.push_front(data);
		}
		else if (tmp[1] == 'o' && tmp[4] == 'b') {
			if (A.empty()) ans[cnt++] = -1;
			else {
				ans[cnt++] = A.back();
				A.pop_back();
			}
		}
		else if (tmp[1] == 'o' && tmp[4] == 'f') {
			if (A.empty()) ans[cnt++] = -1;
			else {
				ans[cnt++] = A.front();
				A.pop_front();
			}
		}
		else if (tmp[1] == 'i') {
			ans[cnt++] = A.size();
		}
		else if (tmp[1] == 'm') {
			ans[cnt++] = A.empty();
		}
		else if (tmp[0] == 'f') {
			if (A.empty()) ans[cnt++] = -1;
			else ans[cnt++] = A.front();
		}
		else if(tmp[0] == 'b') {
			if (A.empty()) ans[cnt++] = -1;
			else ans[cnt++] = A.back();
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	}
}

/*/
class deque {
	public:
		int size;
		vector<int> Ds;
		
		deque() { size = 0;	}
		void push_front(int data) {
			if (!size) Ds.push_back(data);
			else Ds.insert(Ds.begin(),data);
			size++;
		}
		void push_back(int data) {

			Ds.push_back(data);
			size++;
		}
		int pop_front() {
			if (!size) return -1;
			int	tmp = Ds[0];
			if (size == 1) {
				Ds.clear(); size = 0;
			}
			else {
				Ds.erase(Ds.begin());
				size--;
			}
			return tmp;
		}
		int pop_back() {
			if (!size) return -1;
			int	tmp = Ds[size-1];
			if (size == 1) {
				Ds.clear(); size = 0;
			}
			else {
				Ds.erase(Ds.end());
				size--;
			}
			return tmp;

		}
		int get_size() { return size; }
		bool isEmpty() { if (size == 0) return 1; else return 0; } 
		int get_front() {
			if (!size) return -1;
			int	tmp = Ds[0];
			return tmp;
		}
		int get_back() {
			if (!size) return -1;
			int	tmp = Ds[size-1];
			return tmp;
		}
};

int main() {
	int N;
	deque A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char tmp[15];
		int data;
		scanf("%s", &tmp, &data);
		if (strcmp(tmp,"push_back") == 0) {
			scanf("%d", &data);
			A.push_back(data);
		}
		else if (strcmp(tmp, "push_front") == 0) {
			scanf("%d", &data);
			A.push_front(data);
		}
		else if (strcmp(tmp, "pop_back") == 0) {
			printf("%d\n", A.pop_back());
		}
		else if (strcmp(tmp, "pop_front") == 0) {
			printf("%d\n", A.pop_front());
		}
		else if (strcmp(tmp, "size") == 0) {
			printf("%d\n", A.get_size());
		}
		else if (strcmp(tmp, "empty") == 0) {
			printf("%d\n", A.isEmpty());
		}
		else if (strcmp(tmp, "front") == 0) {
			printf("%d\n", A.get_front());
		}
		else {
			printf("%d\n", A.get_back());
		}
	}
}
*/