#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <vector>

using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>

typedef struct block {
	int scnt;
	int size[4];
	int sp[4][6][6];
	
	block() { scnt = 0;  };
}block;

block tp[7];
int map[111][111];
int c, p, mh,ans;
void init() {
	tp[0].scnt = 2;
	tp[0].size[0] = 1;
	tp[0].sp[0][0][0] = 1;
	tp[0].sp[0][1][0] = 1;
	tp[0].sp[0][2][0] = 1;
	tp[0].sp[0][3][0] = 1;
	tp[0].size[1] = 4;
	tp[0].sp[1][0][0] = 1;
	tp[0].sp[1][0][1] = 1;
	tp[0].sp[1][0][2] = 1;
	tp[0].sp[1][0][3] = 1;


	tp[1].scnt = 1;
	tp[1].size[0] = 2;
	tp[1].sp[0][0][0] = 1;
	tp[1].sp[0][1][0] = 1;
	tp[1].sp[0][0][1] = 1;
	tp[1].sp[0][1][1] = 1;
	

	tp[2].scnt = 2;
	tp[2].size[0] = 3;
	tp[2].sp[0][0][1] = 1;
	tp[2].sp[0][0][2] = 1;
	tp[2].sp[0][1][0] = 1;
	tp[2].sp[0][1][1] = 1;
	tp[2].size[1] = 2;
	tp[2].sp[1][0][0] = 1;
	tp[2].sp[1][1][0] = 1;
	tp[2].sp[1][1][1] = 1;
	tp[2].sp[1][2][1] = 1;

	tp[3].scnt = 2;
	tp[3].size[0] = 3;
	tp[3].sp[0][0][0] = 1;
	tp[3].sp[0][0][1] = 1;
	tp[3].sp[0][1][1] = 1;
	tp[3].sp[0][1][2] = 1;
	tp[3].size[1] = 2;
	tp[3].sp[1][0][1] = 1;
	tp[3].sp[1][1][1] = 1;
	tp[3].sp[1][1][0] = 1;
	tp[3].sp[1][2][0] = 1;


	tp[4].scnt = 4;
	tp[4].size[0] = 3;
	tp[4].sp[0][0][1] = 1;
	tp[4].sp[0][1][0] = 1;
	tp[4].sp[0][1][1] = 1;
	tp[4].sp[0][1][2] = 1;
	tp[4].size[1] = 2;
	tp[4].sp[1][0][0] = 1;
	tp[4].sp[1][1][0] = 1;
	tp[4].sp[1][2][0] = 1;
	tp[4].sp[1][1][1] = 1;
	tp[4].size[2] = 3;
	tp[4].sp[2][0][0] = 1;
	tp[4].sp[2][0][1] = 1;
	tp[4].sp[2][0][2] = 1;
	tp[4].sp[2][1][1] = 1;
	tp[4].size[3] = 2;
	tp[4].sp[3][0][1] = 1;
	tp[4].sp[3][1][1] = 1;
	tp[4].sp[3][1][0] = 1;
	tp[4].sp[3][2][1] = 1;

	tp[5].scnt = 4;
	tp[5].size[0] = 3;
	tp[5].sp[0][0][2] = 1;
	tp[5].sp[0][1][0] = 1;
	tp[5].sp[0][1][1] = 1;
	tp[5].sp[0][1][2] = 1;
	tp[5].size[1] = 2;
	tp[5].sp[1][0][0] = 1;
	tp[5].sp[1][1][0] = 1;
	tp[5].sp[1][2][0] = 1;
	tp[5].sp[1][2][1] = 1;
	tp[5].size[2] = 3;
	tp[5].sp[2][0][0] = 1;
	tp[5].sp[2][0][1] = 1;
	tp[5].sp[2][0][2] = 1;
	tp[5].sp[2][1][0] = 1;
	tp[5].size[3] = 2;
	tp[5].sp[3][0][1] = 1;
	tp[5].sp[3][1][1] = 1;
	tp[5].sp[3][0][0] = 1;
	tp[5].sp[3][2][1] = 1;

	tp[6].scnt = 4;
	tp[6].size[0] = 3;
	tp[6].sp[0][0][0] = 1;
	tp[6].sp[0][1][0] = 1;
	tp[6].sp[0][1][1] = 1;
	tp[6].sp[0][1][2] = 1;
	tp[6].size[1] = 2;
	tp[6].sp[1][0][0] = 1;
	tp[6].sp[1][1][0] = 1;
	tp[6].sp[1][2][0] = 1;
	tp[6].sp[1][0][1] = 1;
	tp[6].size[2] = 3;
	tp[6].sp[2][0][0] = 1;
	tp[6].sp[2][0][1] = 1;
	tp[6].sp[2][0][2] = 1;
	tp[6].sp[2][1][2] = 1;
	tp[6].size[3] = 2;
	tp[6].sp[3][0][1] = 1;
	tp[6].sp[3][1][1] = 1;
	tp[6].sp[3][2][0] = 1;
	tp[6].sp[3][2][1] = 1;

}

int main() {
	scanf("%d %d", &c, &p);
	init();
	for (int i = 0; i < c; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int j = 110; j + tmp >= 110; j--) {
			map[j][i] = 1;
		}

	}
	
	int cnt = 0;
	while (cnt < tp[p-1].scnt) {
		for (int i = 0; i < c - tp[p - 1].size[cnt] + 1; i++) {
			vector<pii> now;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (tp[p - 1].sp[cnt][j][k]) {
						now.push_back(make_pair(j, k+i));
					}
				}
			}
			while (1) {
				bool flag = 0;
				for (int j = 0; j < now.size(); j++) {
					if (!flag && map[now[j].first + 1][now[j].second]) flag = 1;
				}
				if (!flag) {
					for (int j = 0; j < now.size(); j++) {
						now[j].first += 1;
					}
				}
				else {
					for (int j = 0; j < now.size(); j++) {
						map[now[j].first][now[j].second] = 1;
					}
					bool f2 = 0;
					for (int j = 0; j < now.size(); j++) {
						if (!map[now[j].first + 1][now[j].second]) f2 = 1;
					}
					if (!f2) ans++;
					for (int j = 0; j < now.size(); j++) {
						map[now[j].first][now[j].second] = 0;
					}
					break;
				}

				flag = 0;
			}
		}
		cnt++;
	}
	printf("%d", ans);

}