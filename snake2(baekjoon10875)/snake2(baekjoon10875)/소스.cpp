#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


typedef pair<int, int> P;
typedef pair<int, P> PP;
vector<PP> a[2];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
long long sav[2];
int min(int a, int b) {
	if (a > b) return b;
	return a;
}
int Abs(int a) {
	if (a < 0) return (-a);
	return a;
}
struct Dir {
	int s;
	char dir;
};
Dir Da[1002];
int main() {
	scanf("%d %d", &n, &m);
	int ccc = 0;
	for (int i = 0; i < m; i++) {
		int t1;
		char t2;
		scanf("%d %c", &t1, &t2);
		Da[i] = Dir{ t1, t2 };
	}
	Da[m] = Dir{ 3 * n+1, 'L' };
	int bound = n;
	int x = 0;
	int y = 0;
	int dir = 0;
	long long ans = 0;
	bool flag = 0;
	vector<int> sav[2];
	for (int i = 0; i <= m; i++) {
		int nt = Da[i].s;
		char nd = Da[i].dir;
		int nx = x + nt * dx[dir];
		int ny = y + nt * dy[dir];
		for (int j = 0; j < a[!(dir % 2)].size(); j++) {
			if (dir % 2) {
				if (a[0][j].second.first <= x && a[0][j].second.second >= x) {
					if ((y < a[0][j].first && ny >= a[0][j].first) || (y > a[0][j].first && ny <= a[0][j].first)) {
						sav[0].push_back(Abs(a[0][j].first - y));
						flag = 1;
					}
				}
			}
			else {
				if (a[1][j].second.first <= y && a[1][j].second.second >= y) {
					if ((x < a[1][j].first && nx >= a[1][j].first) || (x > a[1][j].first && nx <= a[1][j].first)) {
						sav[0].push_back(Abs(a[1][j].first - x));
						flag = 1;
					}
				}
			}
		}
		for (int j = 0; j < a[(dir % 2)].size(); j++) {
			if (dir == 0 && a[0][j].first == y) {
				if (nx >= a[0][j].second.first && nx <= a[0][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.first - x));
					flag = 1;
					
				}
				if (x < a[0][j].second.first && nx > a[0][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.first - x));
					flag = 1;
					
				}
			}
			if (dir == 2 && a[0][j].first == y) {
				if (nx >= a[0][j].second.first && nx <= a[0][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.second - x));
					flag = 1;
					
				}
				if (x > a[0][j].second.first && nx < a[0][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.second - x));
					flag = 1;
					
				}
			}
			if (dir == 1 && a[1][j].first == x) {
				if (ny >= a[1][j].second.first && ny <= a[1][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.second - y));
					flag = 1;
					
				}
				if (y > a[1][j].second.first && ny < a[1][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.second - y));
					flag = 1;
					
				}
			}
			if (dir == 3 && a[1][j].first == x) {
				if (ny >= a[1][j].second.first && ny <= a[1][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.first - y));
					flag = 1;
					
				}
				if (y < a[1][j].second.first && ny > a[1][j].second.second) {
					sav[1].push_back(Abs(a[0][j].second.first - y));
					flag = 1;
				
				}
			}
			
		}
		if (flag) {
			int m_0 = 3*bound;
			for (int i = 0; i < sav[0].size(); i++) {
				m_0 = min(m_0, sav[0][i]);
			}
			int m_1 = 3 * bound;
			for (int i = 0; i < sav[1].size(); i++) {
				m_1 = min(m_1, sav[1][i]);
			}
			int m_r = min(m_0, m_1);
			printf("%lld", ans + m_r);
			return 0;
		}
		if (Abs(ny) > bound) {
			if(ny > 0) ans += (bound - y) +1;
			else ans += bound + y+1;
			printf("%lld", ans);
			return 0;
		}
		if (Abs(nx) > bound) {
			if(nx > 0) ans += (bound - x) +1;
			else ans += bound + x +1;
			printf("%lld", ans);
			return 0;
		}
		if (dir % 2) {
			if(y < ny) a[1].push_back(PP(x, P(y, ny)));
			else a[1].push_back(PP(x, P(ny, y)));
		}
		else {
			if(x < nx) a[0].push_back(PP(y, P(x, nx)));
			else a[0].push_back(PP(y, P(nx, x)));
		}
		ans += Abs(nt*dx[dir]) + Abs(nt*dy[dir]);
		if (nd == 'L') dir = (dir + 3) % 4;
		else if (nd == 'R') dir = (dir + 1) % 4;

		y = ny;
		x = nx;
	}
		

}