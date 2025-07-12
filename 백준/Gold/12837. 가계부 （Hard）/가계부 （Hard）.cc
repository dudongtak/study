#include<iostream>
#include<vector>
using namespace std;

int N, Q;
typedef long long ll;
vector<ll> tree(4000004,0);

void update(int node, int s, int e, int idx, int diff) {
	if (idx<s || idx>e)return;

	
	tree[node] += diff;
	if (s == e)return;

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || s > r)return 0;

	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;

	for (int i = 0; i < Q; i++) {
		int op, p, q;
		cin >> op >> p >> q;
		
		if (op == 1) {
			update(1, 1, N, p, q);
		}
		else {
			cout << query(1, 1, N, p, q) << "\n";
		}
	}
}