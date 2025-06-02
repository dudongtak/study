#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int N, M, l, r;
ll INF = 10000000001;
vector<ll> arr(100001, 0);
vector<ll> max_tree(400004, 0);
vector<ll> min_tree(400004, INF);

ll init_max(int node, int s, int e) {
	if (s == e)return max_tree[node] = arr[s];
	int m = (s + e) / 2;

	return max_tree[node] = max(init_max(node * 2, s, m), init_max(node * 2 + 1, m + 1, e));
}

ll init_min(int node, int s, int e) {
	if (s == e)return min_tree[node] = arr[s];
	int m = (s + e) / 2;

	return min_tree[node] = min(init_min(node * 2, s, m), init_min(node * 2 + 1, m + 1, e));
}

ll find_max(int node, int s, int e, int l, int r) {
	if (l > e || r < s)return 0;

	if (l <= s && e <= r)return max_tree[node];

	int m = (s + e) / 2;

	return max(find_max(node * 2, s, m, l, r), find_max(node * 2 + 1, m + 1, e, l, r));
}

ll find_min(int node, int s, int e, int l, int r) {
	if (l > e || r < s)return INF;

	if (l <= s && e <= r)return min_tree[node];

	int m = (s + e) / 2;

	return min(find_min(node * 2, s, m, l, r), find_min(node * 2 + 1, m + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)cin >> arr[i];

	init_max(1, 1, N);
	init_min(1, 1, N);

	for (int i = 0; i < M; i++) {
		cin >> l >> r;
		cout << find_min(1, 1, N, l, r) << " " << find_max(1, 1, N, l, r) << "\n";
	}
}