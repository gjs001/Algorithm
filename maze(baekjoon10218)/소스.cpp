#define _CRT_SECURE_NO_WARNINGS	

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define pii pair<int, int>

struct meue {
	set<pii> a;
	string chr;
	int depth;
};



int t, w, h;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,  0, 1, -1 };
char spell[4] = { 'R', 'L', 'D','U' };

int main() {
	cin >> t;


	while (t--) {
		cin >> h >> w;
		char map[13][13] = { 0, };
		set<pii> start;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.') start.insert(make_pair(i, j));
			}
		}
		int cnt = 0;
		queue<meue> que;
		string ans = "";
		que.push(meue{ start, "", 0 });
		int endcon = 0;
		while (que.size()) {
			while (que.front().depth == cnt) {
				meue now = que.front();
				que.pop();

				char nchr;
				if (now.chr.length() == 0) nchr = NULL;
				else nchr = now.chr[now.chr.length() - 1];
				
				for (int i = 0; i < 4; i++) {
					if (nchr == spell[i]) continue;

					if (nchr == 'R' && spell[i] == 'L') continue;
					else if (nchr == 'L' && spell[i] == 'R') continue;
					else if (nchr == 'U' && spell[i] == 'D') continue;
					else if (nchr == 'D' && spell[i] == 'U') continue;
					set<pii> ns;
					set<pii> ::iterator iter;
					bool flag = 0;
					for (iter = now.a.begin(); iter != now.a.end(); ++iter) {
						int y = iter->first;
						int x = iter->second;
						
						while (1) {
							if (map[y + dy[i]][x + dx[i]] == '#') break;
							else if (map[y + dy[i]][x + dx[i]] == '.') {
								y += dy[i];
								x += dx[i];
							}
							else if (map[y + dy[i]][x + dx[i]] == 'O') {
								flag = 1;
								break;
							}
						}
						if(!flag) ns.insert(make_pair(y, x));
						flag = 0;
						
					}

					if (ns.size() == 0) {
						ans = now.chr + spell[i];
						endcon = 1;
					}
					if (endcon) break;
					que.push(meue{ ns, now.chr + spell[i], now.depth + 1 });
				}
				if (endcon) break;
			}
			if (endcon) break;

			if (++cnt == 10) break;
		}
		if (cnt == 10 || ans == "") cout << "XHAE" << endl;
		else cout << ans << endl;
	}

}
