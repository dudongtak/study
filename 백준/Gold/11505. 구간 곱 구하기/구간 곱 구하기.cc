#include<iostream>
#include<vector>
using namespace std;

int N, M, K;
typedef long long ll;
vector<ll> arr(1000001);
vector<ll> tree(4000004);

ll init(int node, int s, int e) {
	if (s == e)return tree[node] = arr[s];
	int m = (s + e) / 2;

	return tree[node] = (init(node * 2, s, m)*init(node * 2 + 1, m + 1, e)) % 1000000007;
}

ll mul(int node, int s, int e, int l, int r) {
	if (l > e || r < s)return 1;

	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;

	return (mul(node * 2, s, m, l, r)*mul(node * 2 + 1, m + 1, e, l, r)) % 1000000007;
}

ll update(int node, int s, int e, int idx, ll num) {
	if (e < idx || idx < s)return tree[node];

	if (s == e)return tree[node] = num;

	int m = (s + e) / 2;
	tree[node] = (update(node * 2, s, m, idx, num)*update(node * 2 + 1, m + 1, e, idx, num)) % 1000000007;
	return tree[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i + 1];
	}

	init(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			update(1, 1, N, b, c);
		}
		else {
			cout << mul(1, 1, N, b, c) << "\n";
		}
	}
}