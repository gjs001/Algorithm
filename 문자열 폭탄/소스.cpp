#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

char tc[1000005];
char ans[1000005];
char tmp[40];
int save[200];
int status[40];
int n;
char lw;
int boomsize;
stack<char> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	cin >> tmp;
	int cnt = 0;
	while (1)
	{

		if (tmp[cnt] == 0) {
			lw = tmp[cnt - 1];
			break;
		}
		save[(int)tmp[cnt]] = cnt+1;
		cnt++;
	}
	boomsize = cnt;
	int size = strlen(tc);
	int cur = 1;
	//memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < size; i++)
	{
		
		if (lw == tc[i]) {
			memset(tmp, 0, sizeof(tmp));
			for (int j = 0; j < boomsize - 1; j++) {
				int idx = (int)st.top();
				if (save[idx] == (boomsize - 1) - j) {
					tmp[j] = st.top();
					st.pop();
				}
				else {
					while (j--) {
						st.push(tmp[j]);
					}
					st.push(tc[i]);
					break;
				}
			}
		}
		else {
			st.push(tc[i]);
		}
	}
	cnt = st.size();
	while (!st.empty()) {
		ans[--cnt] = st.top();
		st.pop();
	}
	if (strlen(ans))	cout << ans;
	else cout << "FRULA";

}