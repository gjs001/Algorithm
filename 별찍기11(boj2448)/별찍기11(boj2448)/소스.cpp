#include <iostream>

using namespace std;

#define MAX 3*2*2*2*2*2*2*2*2*2*2

int map[MAX+1][MAX*2];
char tmp[3][7] = { "  *  "," * * ","*****" };

int n;

int dfs(int idx) {
	return 1;
}

int main() {
	cin >> n;
	int mid = n - 1;
	cout << tmp[0] << "\n";
	cout << tmp[1] << "\n";
	cout << tmp[2] << "\n";
}
