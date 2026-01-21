#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, m, k, a, b;
typedef pair<int, int> pii;
typedef long long ll;

void add(int idx, int val, vector<ll> &t) {
	while (idx <= 1000) {
		t[idx] += val;
		idx += (idx&-idx);
	}
}

ll sum(int idx,vector<ll> &t) {
	ll res = 0;
	while (idx > 0) {
		res += t[idx];
		idx &= (idx - 1);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	int num = 1;
	while (t--) {
		cin >> n >> m >> k;

		vector<pii> road;
		vector<ll> tree(1001);
		ll answer = 0;

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			road.push_back({ a,b });
		}

		sort(road.begin(), road.end());

		for (int i = k - 1; i >= 0; --i) {
			answer += sum(road[i].second - 1,tree);
			add(road[i].second, 1, tree);
		}

		cout << "Test case " << num++ << ": " << answer << "\n";
	}
}