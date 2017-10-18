#include <iostream>

using namespace std;

int n, p, s, ans = -1001;
int mi = -1001;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	int mflag = 1;
	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;
		if (now >= 0) {
			mflag = 0;
			p += now;
			s += now;
		}
		else{
			if(p > s + now)	s = p;
			else s += now;
			p += now;
			if (p < 0) p = 0;
			if (mi < now) mi = now;
		}

		if (ans < s) ans = s;
	}
	if (mflag) cout << mi;
	else cout << ans;
	
}
