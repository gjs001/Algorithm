#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int visit[100005];
int limit;
int mc;

void dfs(int cur, int time) // 백트래킹
{
	if (cur < 0 || time >= limit) return; // 예외처리 : 현재 위치가 음수가 되거나 현재까지 찾은 정답값보다 시간이 오래지났을 때

	if (visit[cur] && visit[cur] < time) return; // 예외처리 : 방문한곳은 패스

	if (cur == k) { // 도착 
		limit = time;
		return;
	}

	visit[cur] = time; // 방문
	
	if (cur * 2 <= k + 1) dfs(cur * 2, time + 1); // 가지치기 :  2배했을 때 k보다 크면 (k가 홀수의 경우 k+1까지) 2배를 하지 않는다! 

	if(cur < k && cur *2 > k) // 가지치기 : k보다 현재위치가 작고 cur*2가 k보다 클 때 다음 2 경우 중 하나가 최단거리이다.
	{
			limit = min(limit, k - cur + time); // 경우 1 : 현재 위치에서 +1로만 사용해서 이동할 때 최단거리
			int tmp = 0;
			tmp = cur - ((k+1) / 2);			// tmp는 cur에서 tmp를 뺐을 때 나온 값 cur-tmp의 2배가 k 혹은 k+1이게 해주는 값
			if(tmp) dfs(cur - tmp, time + tmp); // 경우 2 : cur - tmp한 값을 다시 2배해서 k 혹은 k+1(k가 홀수일 때)가 나오는 위치가 최단거리
	}
	else					
	{
		if (cur < k) dfs(cur + 1, time + 1);		  // 가지치기 : cur가 k보다 크면 +1해줄 필요가 없다. 항상 - 방향으로 가야함
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