#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int run(int dif, string s) {
	int ans = 0;
	int cnt = 0;
	for (int i = dif; i < s.size() - dif + 1; i+=dif) {
		string left = s.substr(i, dif);
		string right = s.substr(i - dif, dif);
		if (left.compare(right) == 0) {
			cnt++;
		}
		else {
			if (cnt > 0) {
				ans += dif*(cnt + 1) - (dif + 1);
				cnt++;
				if (cnt >= 100) {
					ans -= 2;
				}
				else if (cnt >= 10) {
					ans--;
				}
			}
			cnt = 0;
		}
	}
	if (cnt > 0) {
		ans += dif*(cnt + 1) - (dif + 1);
		cnt++;
		if (cnt >= 100) {
			ans -= 2;
		}
		else if (cnt >= 10) {
			ans--;
		}
	}
	return s.size() - ans;
}


int solution(string s) {
	int answer = 10000000;

	for (int i = 1; i <= s.size(); i++) {
		int ret = run(i, s);
		answer = min(answer, ret);
	}
	return answer ;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	for (int i = 0; i < 100; i++)s += "a";
	int ans = solution(s);
	
	cout << ans;
}	