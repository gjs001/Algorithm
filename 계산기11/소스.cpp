#include <iostream>

using namespace std;

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int size;
		cin >> size;
		int ans = 0;
		for (int i = 0; i < size; i++)
		{
			char tmp;
			cin >> tmp;
			if (tmp >= '0') ans += (tmp - '0');
		}
		cout << "#" << t << " " << ans << "\n";
	}
	
}