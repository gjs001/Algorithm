#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
typedef struct node {
	node* l;
	node* r;
	int val;
	node() {};
	node(int x) { val = x; }
}node;
node T[(1 << 18) + 25 * 100000], *seg_root[100001];


typedef struct Data {
	int original_data;
	int input_idx;
	int sorted_idx;
}Data;

bool cmp1(Data a, Data b)
{
	return a.original_data < b.original_data;
}
bool cmp2(Data a, Data b)
{
	return a.input_idx < b.input_idx;
}
int comp[100001];

int tn, n, m;
vector<Data > narr;

node* init_seg(int depth)
{
	if (depth < 0) return NULL;
	node* now = &T[tn++];
	now->l = init_seg(depth - 1);
	now->r = init_seg(depth - 1);
	return now;
}

void init()
{
	seg_root[0] = init_seg(18);
}

void add(node* prev, node* next, int depth, int data)
{
	next->val = prev->val + 1;
	if (depth < 0) return;
	if (data >> depth & 1)
	{
		next->l = prev->l;
		next->r = &T[tn++];
		add(prev->r, next->r, depth - 1, data);
	}
	else
	{
		next->r = prev->r;
		next->l = &T[tn++];
		add(prev->l, next->l, depth - 1, data);
	}
}

int kth(node *prev, node *next, int depth, int k)
{
	if (depth < 0) return 0;
	int res = next->l->val - prev->l->val;
	if (res >= k) return kth(prev->l, next->l, depth - 1, k);
	else return 1 << depth | kth(prev->r, next->r, depth - 1, k - res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	narr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> narr[i].original_data;
		narr[i].input_idx = i;
	}
	sort(narr.begin(), narr.end(),cmp1);
	for (int i = 0; i < n; i++) narr[i].sorted_idx = i;
	for (int i = 0; i < n; i++) comp[i] = narr[i].original_data;
	sort(narr.begin(), narr.end(), cmp2);

	init();
	for (int i =0; i < n; i++)
	{
		seg_root[i + 1] = &T[tn++];
		add(seg_root[i], seg_root[i + 1], 17, narr[i].sorted_idx);
	}
	for (int i = 0; i < m; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << comp[kth(seg_root[l-1], seg_root[r], 17, k)] << "\n";
	}
}