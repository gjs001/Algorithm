#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <vector>
#include <cstring>
#include <functional>
using namespace std;


#define pii pair<int,int>
#define min(a,b) ((a) < (b) ? (a) : (b))
int N, M;
bool visit[100001];
long long dist[100001];
int link[100001];
int qarr[100001][3];
int p[100001];
int Rank[100001];
vector<pii> glist[100001];
/*
void search(vector<pii> *arr, int start, int target) {
	priority_queue<pii,vector<pii>,greater<pii>> que;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++) dist[i] = INF;

	for (int i = 0; i < arr[start].size(); i++) {
		que.push(arr[start][i]);
	}
	visit[start] = true;
	dist[start] = 0;
	while (que.size()) {
		int cur = que.top().second;
		int weight = que.top().first;
		que.pop();
		visit[cur] = true;
		dist[cur] = min(dist[cur], weight);
		if (cur == target) return;
		for (int i = 0; i < arr[cur].size(); i++) {
			if (!visit[arr[cur][i].second]) {
				pii tmp;
				tmp.second = arr[cur][i].second;
				dist[tmp.second] = min(dist[tmp.second], arr[cur][i].first + weight);
				tmp.first = dist[tmp.second];
				que.push(tmp);
			}
			
		}
	}
	return;
}*/


void search(int s, int e, long long w) {
	
	dist[s] = w;
	visit[s] = true;

	for (int i = 0; i < glist[s].size(); i++) {
		if (!visit[glist[s][i].second]) {
			long long neww = glist[s][i].first;
			search(glist[s][i].second, e, w + neww );
		}
	}
}
int find(int a) {
	return a == p[a] ? a : p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (Rank[a] > Rank[b]) swap(a, b);
	p[a] = b;
	if (Rank[a] == Rank[b]) Rank[b]++;
}
void add(int s, int e, int w) {
	glist[e].push_back(make_pair(w, s));
	glist[s].push_back(make_pair(-w, e));
	merge(s, e);
}


int main() {

	while (1) {

		int cnt = 0;
		memset(glist, 0, sizeof(glist));
		memset(Rank, 0, sizeof(Rank));
		for (int i = 0; i <= N; i++) {
			p[i] = i;
		}
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;

		for (int i = 0; i < M; i++) {
			char cmd;
			int s, e;
			scanf(" %c %d %d", &cmd,&s,&e);
			--s; --e;
			if (cmd == '!') {
				int w;
				scanf("%d",&w);
				add( s, e, w);
			}
			if (cmd == '?') {
				qarr[cnt][0] = find(s) == find(e);
				qarr[cnt][1] = s;
				qarr[cnt][2] = e;
				cnt++;

			}
		}
		memset(dist, 0, sizeof(dist));
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i < N; i++) {
			if(!visit[i])
			search(i, 0, 0);
		}
		for (int i = 0; i < cnt; i++) {
			if (!qarr[i][0]) printf("UNKNOWN\n");
			else printf("%lld\n",-dist[qarr[i][2]]+ dist[qarr[i][1]]);
		}
	}
}