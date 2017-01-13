#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int sArr[500001];
int cArr[8001];
int N;
long long ans;

int average() {
	float avr = 0;
	for (int i = 0; i < N; i++) {
		avr += sArr[i];
	}
	avr /= N;
	if (avr >= 0 && avr - (int)avr >= 0.5) avr++;
	else if (avr < 0 && avr - (int)avr <= -0.5) avr--;
	return avr;
}

int midian() {

	return sArr[((N - 1) / 2)];
}
bool cmp(int a, int b) {
	if (a > b) return 1;
	else return 0;
}
int countnum() {
	vector<int> a;
	int maxc = 0;

	for (int i = 0; i < N; i++) {
		if (sArr[i] < 0) {
			cArr[sArr[i] + 4000]++;
			if (maxc < cArr[sArr[i]+ 4000]) {
				maxc = cArr[sArr[i]+ 4000];
			}

		}
		else
		{
			cArr[sArr[i] + 4000]++;
			if (maxc < cArr[sArr[i] + 4000]) {
				maxc = cArr[sArr[i] + 4000];
			}
		}
	}
	for (int i = 0; i < 8000; i++) {
		if (cArr[i] == maxc) a.push_back(i-4000);
	}
	if (a.size() == 1) return a[0];
	else sort(a.begin(), a.end());
	return a[1] ;
}
int check_minmax() {
	int max = -4000;
	int min = 4000;
	for (int i = 0; i < N; i++) {
		if(max < sArr[i]) max = sArr[i];
		if (min > sArr[i]) min = sArr[i];
	}
	return max - min;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &sArr[i]);
	}
	sort(sArr, sArr + N);
	int avr = average();
	int mid = midian();
	int cn = countnum();
	int range = check_minmax();
	printf("%d\n%d\n%d\n%d\n", avr, mid, cn, range);

}