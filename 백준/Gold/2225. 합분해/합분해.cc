#include<vector>
#include<iostream>
using namespace std;

int N, K;
vector<vector<long long>> dp(201, vector<long long>(201, 0));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)dp[1][i] = 1;

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += (dp[i - 1][j - l] % 1000000000);
			}
		}
	}

	cout << dp[K][N] % 1000000000;
}