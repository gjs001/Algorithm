#include <iostream>
#include <stack>
using namespace std;

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int size;
		cin >> size;
		stack<char> st;
		int ans = 0;
		char map[1001];
		cin >> map;
		for (int i = 0; i < size; i++)
		{
			char tmp;
			tmp = map[i];
			
			if (tmp == ']' || tmp == '}' || tmp == '>' || tmp == ')')
			{
				if (st.empty())
					break;
				else if (((tmp & 1 << 4) && st.top() == tmp - 2) || (!(tmp & 1 << 4) && st.top() == tmp - 1))
					st.pop();
				else
					break;
			}
			else
			{
				st.push(tmp);
			}
			if (i == size - 1 && st.empty()) ans = 1;
		}
		
		cout << "#" << t << " " << ans << "\n";
	}
}