#include<iostream>
#include<vector>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	if (N == 2) {
		cout << 3;
		return 0;
	}
	else if (N % 2 == 1) {
		cout << 0;
		return 0;
	}

	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i+=2) {
		dp[i] += dp[i - 2] * 3;
		for (int j = 0; j < i-2; j += 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
}