#include    <cstdio>
#include    <string>
#include    <iostream>
#pragma warning(disable:4996)

struct S
{
	int n;
	char p;
};
S st[33];
int top = 1;
int main()
{
	std::string s;
	std::cin >> s;
	int res;

	for (int i = 0; i < s.length(); ++i)
	{
		res = 0;
		if (s[i] == '(' || s[i] == '[')
			st[top++].p = s[i];
		else
		{
			if (s[i] == ')')
			{
				while (top > 1)
				{
					top--;
					if (st[top].p != 'n' && st[top].p != '(') //숫자도 아니고 (도 아닌 경우 
					{
						printf("0");
						return 0;
					}
					if (st[top].p == '(')
					{
						st[top].p = 'n';
						if (res == 0) res = 1;
						st[top++].n = res * 2;
						break;
					}
					res += st[top].n;
				}
			}
			else if (s[i] == ']')
			{
				while (top > 1)
				{
					top--;
					if (st[top].p != 'n' && st[top].p != '[') //숫자도 아니고 [도 아닌 경우 
					{
						printf("0");
						return 0;
					}
					if (st[top].p == '[')
					{
						st[top].p = 'n';
						if (res == 0) res = 1;
						st[top++].n = res * 3;
						break;
					}
					res += st[top].n;
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i < top; ++i)
	{
		if (st[i].p != 'n')
		{
			printf("0");
			return 0;
		}
		result += st[i].n;
	}
	printf("%d", result);

	return 0;
}

