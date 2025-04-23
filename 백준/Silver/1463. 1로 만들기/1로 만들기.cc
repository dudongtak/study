#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> dp(1000001, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 1000000; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]);
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]);
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]);
		}
		else dp[i] = dp[i - 1];
		dp[i]++;
	}

	cin >> N;
	cout << dp[N];
}