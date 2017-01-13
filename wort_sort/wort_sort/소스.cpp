#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool cmp(const pair<int, string> &a1, const pair<int, string> &a2) {
	if (a1.first < a2.first) return 1;
	else if (a1.first > a2.first) return 0;
	else {
		if (a1.second.compare(a2.second) < 0) return 1;
		else return 0;
	}
}


int main() {
	vector<pair<int,string>> qArr;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char tmp[50];
		scanf("%s", &tmp);
		qArr.push_back(make_pair(strlen(tmp), tmp));
  }
	sort(qArr.begin(), qArr.end(),cmp);

	string tmp;

	for (int i = 0; i<N; i++) {
		if (i == 0) {
			tmp = qArr[0].second;
			printf("%s\n", qArr[i].second.c_str());
		}
		if (tmp == qArr[i].second) continue;
		else
			tmp = qArr[i].second;

		
		printf("%s\n", qArr[i].second.c_str());

	}
}