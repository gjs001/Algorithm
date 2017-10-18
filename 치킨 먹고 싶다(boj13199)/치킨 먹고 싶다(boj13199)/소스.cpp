#include <iostream>

using namespace std;

int price, money, f, c;

long long dfs(int num, int add) {
	if (num*c+add < f) {
		return num;
	}
	long long res = num;
	int t1 = (num*c + add) / f;
	int t2 = (num*c + add) % f;
	res += dfs(t1, t2);
	return res;
}

int main() {
	int t;
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> price >> money >> f >> c;
		int tmp = money / price;
		long long sangun = dfs(tmp, 0);
		long long dooyoung = tmp + (tmp*c) / f;
		cout << sangun - dooyoung << "\n";

	}
}