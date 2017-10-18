#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;


int n;

int main() {
	std::ios::sync_with_stdio(false);
	int tmp;
	cin >> n;
	vector<pair<int, int>> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	int _max = 0;
	for (int i = 0; i < n; i++) {
		_max = max(_max, A[i].second - i);
	}
	cout << _max + 1;
}