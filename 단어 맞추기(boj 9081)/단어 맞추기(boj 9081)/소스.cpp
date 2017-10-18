#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


char word[103];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> word;
		char tmp[103];
		int cnt = 0;
		int n = strlen(word);
		int pivot = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (pivot <= word[i] - 'A') {
				pivot = word[i] - 'A';
				tmp[cnt++] = word[i];
			}
			else {
				int idx = cnt-1;
				for (int j = 0; j < cnt; j++) {
					if (word[i] < tmp[j] && pivot + 'A' > tmp[j]) {
						pivot = tmp[j] - 'A';
						idx = j;
				  }
				}

				tmp[idx] = word[i];
				word[i] = pivot + 'A';
				sort(tmp, tmp + cnt);
				for (int j = 0; j < cnt; j++) {
					word[i + j + 1] = tmp[j];
				}
				break;
			}
		}
		cout << word << "\n";
	}
}