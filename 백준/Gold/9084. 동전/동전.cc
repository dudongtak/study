#include<iostream>
#include<vector>
using namespace std;

int T, N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<int> dp(10010, 0);
		vector<int> coin(21);

		cin >> N;
		for (int j = 1; j <= N; j++)cin >> coin[j];
		cin >> M;

		dp[0] = 1;

		for (int j = 1; j <= N; j++) {
			for (int k = coin[j]; k <= M; k++) {
				dp[k] = dp[k] + dp[k - coin[j]];
			}
		}
		cout << dp[M] << "\n";
	}
}