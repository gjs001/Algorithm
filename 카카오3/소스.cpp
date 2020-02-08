#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<vector<int>> key_ro;

typedef pair<int, int> pii;

void rotation(vector<vector<int>> key) {
	int size = key.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			key_ro[i][j] = key[size - j - 1][i];
		}
	}
}
int map[100][100];
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	key_ro.resize(key.size());
	for (int i = 0; i < key.size(); i++)key_ro[i].resize(key.size());
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			map[i+30][j+30] = lock[i][j];
		}
	}
	int lockcnt = 0;
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			if (lock[i][j] == 0) lockcnt++;
		}
	}
	for (int k = 0; k < 4; k++) {
		if (k > 0) {
			rotation(key);
			key = key_ro;
		}
		int ksize = key.size();
		int lsize = lock.size();

		for (int i = 30 - ksize + 1; i < 30 + lsize + ksize - 1; i++) {
			for (int j = 30 - ksize + 1; j < 30 + lsize + ksize - 1; j++) {
				int badflag = 0;
				int anscnt = 0;
				for (int y = 0; y < ksize; y++) {
					for (int x = 0; x < ksize; x++) {
						if (i+y < 30 || i+y >= 30 + lsize || j+x < 30 || j+x >= 30 + lsize) continue;
						if (map[i+y][j+x] + key[y][x] == 2 || map[i+y][j+x] + key[y][x] == 0) badflag = 1;
						if (map[i+y][j+x] == 0 && key[y][x] == 1) anscnt++;
						if (badflag) break;
					}
					if (badflag) break;
				}
				if (badflag == 0 && anscnt == lockcnt) return true;
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1} , {1,1,0},{1,0,1} };
	cout << solution(key, lock);
}