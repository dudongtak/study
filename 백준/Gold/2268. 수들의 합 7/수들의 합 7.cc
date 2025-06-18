#include<iostream>
#include<vector>
using namespace std;

int N, M, op, i, j;
typedef long long ll;
vector<int> arr(1000001, 0);
vector<ll> tree(4000004, 0);

ll sum(int node, int s, int e, int l, int r) {
	if (l > e || s > r)return 0;

	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;

	return sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r);
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx<s || idx>e)return;

	tree[node] += diff;
	if (s == e)return;

	int m = (s + e) / 2;

	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int k = 0; k < M; k++) {
		cin >> op >> i >> j;

		if (op == 0) {
			if (i < j)cout << sum(1, 1, N, i, j) << "\n";
			else cout << sum(1, 1, N, j, i) << "\n";
		}
		else {
			int diff = j - arr[i];
			arr[i] = j;
			update(1, 1, N, i, diff);
		}
	}
}