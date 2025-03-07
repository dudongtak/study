#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, sum = 0;
vector<vector<int>> dp(101, vector<int>(10001, 0));
vector<int> memory(101, 0);
vector<int> cost(101, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<pair<int, int>> v(n);

	for (int i = 1; i <= n; i++) cin >> memory[i];
	for (int i = 1; i <= n; i++) { 
		cin >> cost[i]; 
		sum += cost[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
}