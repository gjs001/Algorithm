#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

#define dy 29
#define dx 1
#define start 421

int visit[(29 * 29)+1];
int ox[4] = { 1 , -1, 0, 0 };
int oy[4] = { 0, 0 ,1,-1 };

double ans;
double percent[4];

void dfs(int cur, int depth, double prev) {

	visit[cur] = true;

	for (int i = 0; i < 4; i++) {
		int newcur = cur + ox[i] * dx + oy[i] * dy;
		if (visit[newcur]) continue;
		else {
			if (depth - 1 == 0) {
				ans += prev*percent[i];
				continue;
			}
			else dfs(newcur, depth - 1, prev*percent[i]);
		}
	}

	visit[cur] = false;


}

int main() {
	int depth;
	cin >> depth;
	for (int i = 0; i < 4; i++) {
		double tmp;
		cin >> tmp;
		percent[i] = tmp * 0.01;
	}
	dfs(421, depth, 1);
	printf("%.10lf", ans);
}