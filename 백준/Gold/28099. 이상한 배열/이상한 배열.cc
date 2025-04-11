#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

typedef long long ll;
int N, T;

ll init(int node, int s, int e, vector<ll> &tree, vector<ll> &a) {
	if (s == e)return tree[node] = a[s];

	int m = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, m, tree, a), init(node * 2 + 1, m + 1, e, tree, a));
}

ll find_max(int node, int s, int e, vector<ll>&tree, int l, int r) {
	if (r<s || l>e) return 0;
	if (l <= s && e <= r)return tree[node];

	int m = (s + e) / 2;
	return max(find_max(node * 2, s, m, tree, l, r), find_max(node * 2 + 1, m + 1, e, tree, l, r));
}

bool solve() {
	cin >> T;
	vector<ll> arr(T + 1);
	vector<ll> tree(arr.size() * 4);
	unordered_map<ll, vector<int>> idx;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		idx[arr[i]].push_back(i);
	}
	init(1, 1, T, tree, arr);

	bool flag = true;

	for (auto m : idx) {
		if (m.second.size() < 2)continue;
		ll num = m.first;
		vector<int> v = m.second;
		for (int i = 0; i < v.size() - 1; i++) {
			if (num != find_max(1, 1, T, tree, v[i], v[i + 1])) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	while (N > 0) {
		N--;
		if (solve())cout << "Yes\n";
		else cout << "No\n";
	}
}