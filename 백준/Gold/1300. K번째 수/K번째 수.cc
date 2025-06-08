#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	
	ll s = 1, e = K, m;
	ll answer = 0;

	while (s <= e) {
		m = (s + e) / 2;
		ll cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, m / i);
		}

		if (cnt >= K) {
			answer = m;
			e = m - 1;
		}
		else s = m + 1;
	}cout << answer;
}