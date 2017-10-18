#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;

vector<pair<int, int>> A;
int n;

int main(){
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		A.push_back(P(tmp, i));
	}
	sort(A.begin(), A.end());
	int _max = 0;
	for (int i = 0; i < n; i++) {
		_max = max(_max, A[i].second - i);
	}
	printf("%d\n", _max+1);
}