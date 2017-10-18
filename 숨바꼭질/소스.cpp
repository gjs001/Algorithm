#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int visit[100005];
int limit;
int mc;

void dfs(int cur, int time) // ��Ʈ��ŷ
{
	if (cur < 0 || time >= limit) return; // ����ó�� : ���� ��ġ�� ������ �ǰų� ������� ã�� ���䰪���� �ð��� ���������� ��

	if (visit[cur] && visit[cur] < time) return; // ����ó�� : �湮�Ѱ��� �н�

	if (cur == k) { // ���� 
		limit = time;
		return;
	}

	visit[cur] = time; // �湮
	
	if (cur * 2 <= k + 1) dfs(cur * 2, time + 1); // ����ġ�� :  2������ �� k���� ũ�� (k�� Ȧ���� ��� k+1����) 2�踦 ���� �ʴ´�! 

	if(cur < k && cur *2 > k) // ����ġ�� : k���� ������ġ�� �۰� cur*2�� k���� Ŭ �� ���� 2 ��� �� �ϳ��� �ִܰŸ��̴�.
	{
			limit = min(limit, k - cur + time); // ��� 1 : ���� ��ġ���� +1�θ� ����ؼ� �̵��� �� �ִܰŸ�
			int tmp = 0;
			tmp = cur - ((k+1) / 2);			// tmp�� cur���� tmp�� ���� �� ���� �� cur-tmp�� 2�谡 k Ȥ�� k+1�̰� ���ִ� ��
			if(tmp) dfs(cur - tmp, time + tmp); // ��� 2 : cur - tmp�� ���� �ٽ� 2���ؼ� k Ȥ�� k+1(k�� Ȧ���� ��)�� ������ ��ġ�� �ִܰŸ�
	}
	else					
	{
		if (cur < k) dfs(cur + 1, time + 1);		  // ����ġ�� : cur�� k���� ũ�� +1���� �ʿ䰡 ����. �׻� - �������� ������
		dfs(cur - 1, time + 1);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	limit = abs(n - k);
	//memset(visit, -1, sizeof(visit));
	dfs(n, 0);
	cout << limit;
}