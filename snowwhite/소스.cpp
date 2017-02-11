#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int qArr[9];
int tArr[7];

int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &qArr[i]);

	bool flag = false;
	memcpy(tArr, &qArr[2], sizeof(int) * 7);
	int sum = 0;
	for (int i = 0; i < 7; i++) sum += tArr[i];
	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 7; j++) {
			int tmpsum = sum - tArr[j] + qArr[i % 9];
			if (tmpsum == 100) {
				flag = true;
				tArr[j] = qArr[i% 9];
				break;
			}
			tmpsum = sum - tArr[j] + qArr[i % 9];
			if (tmpsum == 100) {
				flag = true;
				tArr[j] = qArr[i % 9];
				break;
			}
		}
		if (flag) break;
		sum -= tArr[i % 7];
		tArr[i%7] = qArr[i% 9];
		sum += qArr[i % 9];
	}
	sort(tArr, tArr + 7);
	for (int i = 0; i < 7; i++) printf("%d\n",tArr[i]);
}

