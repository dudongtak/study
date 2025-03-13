#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> dp(n, 0);
	
	int Max = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (num[i] > num[j])dp[i] = max(dp[i], dp[j] + 1);
		}
		Max = max(Max, dp[i]);
	}
	cout << Max;
}