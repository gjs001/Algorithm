#include <iostream>
#include <vector>


using namespace std;
#define lchild(a) 2*a
#define rchild(a) 2*a+1
int n, k;
vector<int> seg[1 << 19];
int arr[100001];
void seg_merge_tree(int left, int right, int idx, int *ar) {
	if (left < right) {
		int mid = (left + right) / 2;
		seg_merge_tree(left, mid, lchild(idx), ar);
		seg_merge_tree(mid + 1, right, rchild(idx), ar);
		int liter = 0;
		int riter = 0;
		for (int i = 0; i < right - left + 1; i++) {
			if (riter != seg[rchild(idx)].size() && (liter == seg[lchild(idx)].size() || seg[lchild(idx)][liter] > seg[rchild(idx)][riter])) seg[idx].push_back(seg[rchild(idx)][riter]),riter++;
			else seg[idx].push_back(seg[lchild(idx)][liter]),liter++;
		}
	}
	else if (left == right) {
		seg[idx].push_back(ar[left]);
	}
}

int search(int left, int right, int target) {
	if (left < right) {
		int mid = (right + left) / 2
	}
}

int check(int left, int right, int target) {
	
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	seg_merge_tree(0, n - 1, 1, arr);
	for (int i = 0; i < k; i++) {
		int l, r, t;
		scanf("%d %d %d", &l, &r, &t);
		printf("%d\n", check(l, r, t));
	}
}