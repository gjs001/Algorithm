#include<iostream>

using namespace std;

struct node {
	int data;
	node* next;
}tmpnode[100000];

int nodecnt;
node* my_newnode()
{
	return &tmpnode[nodecnt++];
}


struct list {

	int size;
	node* head;
	node* now;
	inline void add_node(int data)
	{
		if (head == nullptr)
		{
			head = my_newnode();
			head->data = data;
			now = head;
			return;
		}
		now->next = my_newnode();
		now = now->next;
		now->data = data;
	}
};



list edgelist[5001];
int visit[5001];
int cache[5001];
int n, k;
int que[5001];
int tail, head;
list tmp;
inline void init()
{
	for (register int j = 0; j <= n; j++)
	{
		visit[j] = 0;
		cache[j] = 0;
	}
	head = tail = 0;
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> n;
		nodecnt = 0;


		for (register int i = 1; i <= n; i++)
		{
			edgelist[i] = tmp;
		}
		for (register int i = 1; i <= n; i++)
		{
			cin >> k;
			for (register int j = 0; j < k; j++)
			{
				int s;
				cin >> s;
				edgelist[s].size++;
				edgelist[s].add_node(i);
			}
		}
		long long ans = (1LL << 63) - 1LL;
		for (register int i = 1; i <= n; i++)
		{
			init();
			que[tail++] = i;
			visit[i] = 1;
			cache[i] = 1;
			long long ret = 1;
			while (head < tail)
			{
				int now = que[head++];
				int depth = cache[now] + 1;
				register node* v = edgelist[now].head;
				for (int j = 1; j <= edgelist[now].size; j++, v = v->next)
				{
					register int next = v->data;
					if (visit[next]) continue;
					cache[next] = depth;
					ret += depth;
					visit[next] = 1;
					que[tail++] = next;
				}
			}
			if (tail != n) continue;

			if (ans > ret) ans = ret;
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}