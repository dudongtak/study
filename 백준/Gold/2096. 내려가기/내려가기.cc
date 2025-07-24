#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> max_dp(3);
	vector<int> min_dp(3);

	cin >> a >> b >> c;
	max_dp[0] = min_dp[0] = a;
	max_dp[1] = min_dp[1] = b;
	max_dp[2] = min_dp[2] = c;

	for (int i = 1; i < N; i++) {
		int tmp0 = max_dp[0], tmp2 = max_dp[2];
		cin >> a >> b >> c;

		max_dp[0] = max(max_dp[0], max_dp[1]) + a;
		max_dp[2] = max(max_dp[2], max_dp[1]) + c;
		max_dp[1] = max(max(tmp0, tmp2), max_dp[1]) + b;

		tmp0 = min_dp[0]; tmp2 = min_dp[2];

		min_dp[0] = min(min_dp[0], min_dp[1]) + a;
		min_dp[2] = min(min_dp[2], min_dp[1]) + c;
		min_dp[1] = min(min(tmp0, tmp2), min_dp[1]) + b;
	}

	cout << *max_element(max_dp.begin(), max_dp.begin() + 3) << " " << *min_element(min_dp.begin(), min_dp.begin() + 3);
}