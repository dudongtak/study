#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> parent;
	vector<ll> sz;

	DSU(int n){
		parent.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int x) {
		return parent[x] == x ? x : parent[x] = Find(parent[x]);
	}

	pair<ll, ll> Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		ll a = sz[x], b = sz[y];
		if (a < b) {
			swap(a, b);
			swap(x, y);
		}
		parent[y] = x;
		sz[x] = a + b;
		ll deltaPairs = a * b;
		ll deltaDist = a * b * (a + b) / 2;
		return { deltaPairs, deltaDist };
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	DSU dsu(N);

	ll totalPairs = 0;
	ll totalDist = 0;

	for (int i = 1; i < N; i++) {
		int u;
		cin >> u;  
		ll dp, dd;
		tie(dp, dd) = dsu.Union(u, u + 1);
		totalPairs += dp;
		totalDist += dd;
		cout << totalPairs << ' ' << totalDist << '\n';
	}
	return 0;
}
