#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int N, M;
vector<ll> dot;
vector<pll> line;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll mood;
		cin >> mood;
		dot.push_back(mood);
	}
	for (int i = 0; i < M; i++) {
		ll x1, x2;
		cin >> x1 >> x2;
		if (x2 < x1)swap(x1, x2);
		line.push_back({ x1,x2 });
	}
	sort(dot.begin(), dot.end());

	ll s, e;
	int idx = 0;
	while (idx < line.size()) {
		s = line[idx].first;
		e = line[idx].second;

		int l = lower_bound(dot.begin(), dot.end(), s) - dot.begin();
		int r = upper_bound(dot.begin(), dot.end(), e) - dot.begin();

		cout << r - l << "\n";
		idx++;
	}
}