#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, op, idx, v;
int INF = 1000000001;
vector<int> arr(100001);
vector<pair<int, int>> tree(400004, { INF,-1 });
pair<int, int> inf = { INF,-1 };

pair<int,int> init(int node, int s, int e) {
	if (s == e)return tree[node] = { arr[s],s };

	int m = (s + e) / 2;

	pair<int, int> p1 = init(node * 2, s, m);
	pair<int, int> p2 = init(node * 2 + 1, m + 1, e);
	if (p1.first == p2.first) return tree[node] = p1;
	else {
		if (p1.first < p2.first)return tree[node] = p1;
		else return tree[node] = p2;
	}
}

pair<int, int> Find(int node, int s, int e, int l, int r) {
	if (r < s || e < l)return inf;

	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;

	pair<int, int> p1 = Find(node * 2, s, m, l, r);
	pair<int, int> p2 = Find(node * 2 + 1, m + 1, e, l, r);

	if (p1.first == p2.first)return p1;
	else {
		if (p1.first < p2.first)return p1;
		else return p2;
	}
}

void update(int node, int s, int e, pair<int,int> p) {
	if (p.second<s || p.second>e)return;

	if (s == e) {
		tree[node] = p;
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, p);
	update(node * 2 + 1, m + 1, e, p);
	pair<int, int> p1 = tree[node * 2];
	pair<int, int> p2 = tree[node * 2 + 1];

	if (p1.first == p2.first)tree[node] = p1;
	else {
		if (p1.first < p2.first)tree[node] = p1;
		else tree[node] = p2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)cin >> arr[i];

	init(1, 1, N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> op >> idx >> v;

		if (op == 2)cout << Find(1, 1, N, idx, v).second << "\n";
		else {
			arr[idx] = v;
			pair<int, int> tmp = { v,idx };
			update(1, 1, N, tmp);
		}
	}
}