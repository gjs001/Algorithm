#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 98765432134
#define mp(i,j,k,l) make_pair(make_pair(i,j),make_pair(k,l))
vector<pair<int, char> > v;
int L, n, a, dir, cx, cy;
long long result;
char b;
//0오른쪽 1 위 2 왼쪽 3 아래
int txy[2][4] = {
	{ 1,0,-1,0 },
	{ 0,-1,0,1 }
};

vector<pair<pair<int, int>, pair<int, int> > > lin;
long long chk(int x1, int y1, int x2, int y2) {
	int wh[2];
	if (x1 == x2) wh[0] = 0;//세로줄
	else wh[0] = 1;
	long long tt = INF;
	for (int i = 0; i < lin.size(); i++) {
		int x3 = lin[i].first.first;
		int y3 = lin[i].first.second;
		int x4 = lin[i].second.first;
		int y4 = lin[i].second.second;
		if (x3 == x4) wh[1] = 0;//세로줄
		else wh[1] = 1;

		int temp = (y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1);

		if (temp == 0) { //평행
			if (wh[1] == 0 && wh[0] == wh[1] && x1 == x3) {
				//y값만 체크
				int t1 = min(y1, min(y2, min(y3, y4)));
				int t2 = max(y1, max(y2, max(y3, y4)));
				int t3 = abs(y1 - y2) + abs(y3 - y4);
				if (t2 - t1 <= t3) tt = min(tt, (long long)abs(y1 - y2) - (t3 - (t2 - t1)));
			}
			else if (wh[1] == 1 && wh[0] == wh[1] && y1 == y3) {
				//x값만 체크
				int t1 = min(x1, min(x2, min(x3, x4)));
				int t2 = max(x1, max(x2, max(x3, x4)));
				int t3 = abs(x1 - x2) + abs(x3 - x4);
				if (t2 - t1 <= t3) tt = min(tt, (long long)abs(x1 - x2) - (t3 - (t2 - t1)));
			}
		}
		else {
			if (wh[0] == 0) {//x1 x2가 세로줄
				if (x3 <= x1 && x1 <= x4 && y1 <= y3 && y3 <= y2)
					tt = min(tt, (long long)(abs(y3 - y1)));
			}
			else {//x3 x4 가 세로줄
				if (x1 <= x3 && x3 <= x2 && y3 <= y1 && y1 <= y4)
					tt = min(tt, (long long)(abs(x3 - x1)));
			}
		}
	}
	//라인넘는지 체크
	if (x2 > L)	tt = min(tt, (long long)abs(x1 - (L + 1)));
	if (x2 < -L) tt = min(tt, (long long)abs(x1 + (L + 1)));
	if (y2 > L) tt = min(tt, (long long)abs(y1 - (L + 1)));
	if (y2 < -L) tt = min(tt, (long long)abs(y1 + (L + 1)));
	return tt;
}

int main() {
	scanf("%d%d", &L, &n);
	for (int i = 0; i < n; i++)
		scanf("%d %c", &a, &b), v.push_back({ a, b });
	int nx, ny;
	for (int i = 0; i < n; i++) {
		nx = cx + (txy[0][dir] * v[i].first);
		ny = cy + (txy[1][dir] * v[i].first);
		//충돌체크
		long long check = chk(cx + txy[0][dir], cy + txy[1][dir], nx, ny);
		//printf("%lld\n", check);
		check++;
		if (INF > check) {
			printf("%lld\n", check + result);
			return 0;
		}
		//방향변경
		if (v[i].second == 'L') dir = (dir + 5) % 4;
		else dir = (dir + 3) % 4;
		lin.push_back(mp(cx, cy, nx, ny));
		cx = nx;
		cy = ny;
		result += v[i].first;
	}

	nx = cx + (txy[0][dir] * (L * 2));
	ny = cy + (txy[1][dir] * (L * 2));
	long long check = chk(cx + txy[0][dir], cy + txy[1][dir], nx, ny);
	check++;
	printf("%lld\n", check + result);
	return 0;
}