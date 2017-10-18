#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int n, a[500001];
ll merge_sort(int start, int end) {
	if (start == end) return 0;
	vector<int> nary(end - start + 1);

	ll ret = 0;
	int mid = (end + start) / 2;
	int idex = 0;
	int left = start;
	int right = mid + 1;
	ret = merge_sort(start, mid) + merge_sort(mid + 1, end);

	while (left <= mid || right <= end) {
		if ((left != mid + 1 && a[left] <= a[right]) || right == end + 1)
			nary[idex++] = a[left++];
		else {
			nary[idex++] = a[right++];
		
			if (left != mid + 1)    ret += (mid - left + 1);
		}
	}

	idex = 0;

	for (int i = start; i <= end; i++) a[i] = nary[idex++];
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	printf("%lld", merge_sort(1, n));
}
