#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#define pii pair<int, int>

int n, q;
int qarr[1000000][2];




int main() {
	cin >> n >> q;
	map<int, int> list;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		list[i] = tmp;
	}
	for (int i = 0; i < q; i++) {
		cin >> qarr[i][0] >> qarr[i][1];

	}

	for (int i = 0; i < q; i++) {
		for (int j = 1; j <= qarr[i][1]; j++) {
			list[qarr[i][0] + j - 2] += j;
		}

	}
	for (int i = 0; i < n; i++) {
		cout << list[i] << " ";
	}

}