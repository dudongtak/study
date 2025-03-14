#include<iostream>
#include<vector>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			long long num;
			cin >> num;
			dp[i][j] = dp[i][j - 1] + num;
		}
	}

	while (m > 0) {
		m--;
		int answer = 0;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		for (int i = sx; i <= ex; i++) {
			answer += dp[i][ey] - dp[i][sy - 1];
		}
		cout << answer << "\n";
	}

}