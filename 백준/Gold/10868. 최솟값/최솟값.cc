#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int Max = 1000000001;
vector<int> arr(100001);
vector<int> tree(400004, Max);

int init(int node, int s, int e) {
	if (s == e)return tree[node] = arr[s];
	int m = (s + e) / 2;
	return tree[node] = min(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

int Min(int node, int s, int e, int l, int r) {
	if (s > r || e < l)return Max;

	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;

	return min(Min(node * 2, s, m, l, r), Min(node * 2 + 1, m + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)cin >> arr[i];
	init(1, 1, N);

	for (int i = 0; i < M; i++) {
		int r, l;
		cin >> l >> r;
		cout << Min(1, 1, N, l, r) << "\n";
	}
}