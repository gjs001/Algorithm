#include<iostream>
#include<queue>
#include<set>
#include<string>
using namespace std;
struct DATA {
	set<pair<int, int>> s;
	string con;
};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char sym[4] = { 'D', 'U', 'R', 'L' };
int main()
{
	int n; cin >> n;
	while (n--)
	{
		int h, w;
		char input[12][12] = { 0, };
		set<pair<int, int>> s;
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			for (int k = 0; k < w; k++)
			{
				cin >> input[i][k];
				if (input[i][k] == '.')
					s.insert(make_pair(k, i));
			}

		int idx = 0, cnt = 0;
		string ans = "";
		queue<DATA> q[2];
		q[idx].push(DATA{ s, "" });

		while (!q[idx].empty())
		{
			while (!q[idx].empty())
			{
				DATA now = q[idx].front();
				q[idx].pop();

				char ch;
				if (now.con.length() == 0) ch = NULL;
				else ch = now.con[now.con.length() - 1];

				for (int i = 0; i < 4; i++)
				{
					if (ch == sym[i]) continue;

					if (ch == 'D' && i == 1) continue;
					else if (ch == 'U' && i == 0) continue;
					else if (ch == 'R' && i == 3) continue;
					else  if (ch == 'L' && i == 2) continue;

					set<pair<int, int>> te;
					set<pair<int, int>>::iterator iter;
					for (iter = now.s.begin(); iter != now.s.end(); ++iter)
					{
						int x = iter->first;
						int y = iter->second;

						while (true)
						{
							if (input[y + dy[i]][x + dx[i]] == '#') break;
							else if (input[y + dy[i]][x + dx[i]] == '.')
							{
								x += dx[i];
								y += dy[i];
							}
							else if (input[y + dy[i]][x + dx[i]] == 'O') goto ups;
						}
						te.insert(make_pair(x, y));
					ups:
						1;
					}
					if (te.size() == 0)
					{
						ans = now.con + sym[i];
						goto end;
					}
					q[!idx].push(DATA{ te, now.con + sym[i] });
				}
			}
			idx = !idx;
			if (++cnt == 10) break;
		}
	end:
		if (cnt == 10 || ans == "") cout << "XHAE" << endl;
		else cout << ans << endl;
	}
	return 0;
}