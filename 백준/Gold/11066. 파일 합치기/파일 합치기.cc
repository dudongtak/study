#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<ll> a(N + 1), ps(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
		}

		vector<vector<ll>> dp(N + 2, vector<ll>(N + 2, 0));
		for (int len = 2; len <= N; len++) {
			for (int i = 1; i + len - 1 <= N; i++) {
				int j = i + len - 1;
				dp[i][j] = INF;
				for (int k = i; k < j; k++) {
					ll cost = dp[i][k] + dp[k + 1][j];
					if (cost < dp[i][j]) dp[i][j] = cost;
				}
				dp[i][j] += ps[j] - ps[i - 1];
			}
		}

		cout << dp[1][N] << "\n";
	}
	return 0;
}