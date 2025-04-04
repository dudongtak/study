#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll INF = 100000000000;
int N, M;
vector<ll> arr(100001);
vector<pair<ll,int>> tree(400004);

pair<ll,int> init(int s, int e, int node) {
	if (s == e)return tree[node] = { arr[s],s };
	int m = (s + e) / 2;
	return tree[node] = min(init(s, m, node * 2), init(m + 1, e, node * 2 + 1));
}

pair<ll,int> query(int s, int e, int node, int l, int r) {
	pair<ll, int> p = { INF,0 };
	if (e<l || s>r)return p;
	if (l <= s && e <= r)return tree[node];
	int m = (s + e) / 2;
	return min(query(s, m, node * 2, l, r), query(m + 1, e, node * 2 + 1, l, r));
}

void update(int s, int e, int node, int idx, ll new_v) {
	if (idx<s || idx>e)return;

	if (s == e) {
		tree[node].first = new_v;
		return;
	}
	int m = (s + e) / 2;
	update(s, m, node * 2, idx,new_v);
	update(m + 1, e, node * 2 + 1, idx, new_v);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;

	init(1, N, 1);

	for (int i = 0; i < M; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int idx;
			ll v;
			cin >> idx >> v;
			arr[idx] = v;
			update(1, N, 1, idx, v);
		}
		else {
			cout << query(1, N, 1, 1, N).second << "\n";
		}
	}
}