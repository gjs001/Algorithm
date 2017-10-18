#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef long long int64;

const int MOD = 1000000007;
const int MAX_VALUE = 100000;

int N;
vector<map<int, int>> POTS;
vector<int64> TREE;

void update(int node, int start, int end, int index, int64 diff) {
	if (index < start || index > end) return;

	TREE[node] = (TREE[node] + diff) % MOD;

	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int64 sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return TREE[node];

	return sum(node * 2, start, (start + end) / 2, left, right)
		+ sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void init() {
	scanf("%d", &N);

	POTS = vector<map<int, int>>(N);

	TREE = vector<int64>(MAX_VALUE << 2);

	for (int i = 0; i < N; ++i) {
		int k, c;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &c);
			++POTS[i][c];
		}
	}
}

int solve() {
	for (auto it = POTS.rbegin(); it != POTS.rend(); ++it) {
		for (auto& p : *it) {
			auto cnt = sum(1, 0, MAX_VALUE, p.first, MAX_VALUE) % MOD;
			update(1, 0, MAX_VALUE, p.first, ((cnt + 1) * p.second) % MOD);
		}
	}

	return (TREE[1] + 1) % MOD;
}

int main() {
	int t;

	freopen("input3.txt", "r", stdin);

	scanf("%d", &t);

	while (t--) {
		init();

		printf("%d\n", solve());
	}
}