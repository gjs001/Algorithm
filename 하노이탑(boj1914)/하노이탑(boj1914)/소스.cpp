#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int n;
string ans;
void hanoi(int depth, int now, int next, int temp) {
	if (depth == 1) {
		if (n <= 20) {
			char tmp[5] = { now + '0',' ',next + '0','\n' };
			ans.append(tmp);
		}
		return;
	}
	hanoi(depth - 1, now, temp, next);
	if (n <= 20) {
		char tmp[5] = { now + '0',' ',next + '0','\n' };
		ans.append(tmp);
	}
	hanoi(depth - 1, temp, next, now);

}

int main() {
	cin >> n;

	long double data = 1.0;
	for (int i = 0; i < n; i++)	data *= 2;

	char str[100000];
	int size;
	sprintf(str, "%.0Lf", data);
	size = strlen(str);
	str[size - 1] = (char)(((int)(str[size - 1] - 48) - 1) + 48);
	printf("%s\n", str);
	if (n <= 20) {
		hanoi(n, 1, 3, 2);
		cout << ans;
	}
}