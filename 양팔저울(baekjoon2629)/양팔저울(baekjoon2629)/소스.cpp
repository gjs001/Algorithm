
#include <iostream>

using namespace std;


int chu[35];

int n, m;

bool ans[2][15000];

int Abs(int a) {
	if (a < 0) return -a;
	return a;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &chu[i]); 
	}
	scanf("%d", &m);

	ans[0][chu[0]] = ans[0][0] = 1;
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j < 15100; j++) {

			ans[1][j] |= ans[0][Abs(j - chu[i])];
			ans[1][j] |= ans[0][j + chu[i]];
			ans[1][j] |= ans[0][j];
			
		}
		for (int j = 0; j < 15100; j++) ans[0][j] |= ans[1][j];
	}


	for (int i = 0; i < m; i++) {
		int quest;
		scanf("%d", &quest);
		if (quest > 15000 || !ans[1][quest]) cout << "N ";
		else cout << "Y ";

	}

}