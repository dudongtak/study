#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> r(501);
vector<int> c(501);
int num = pow(2, 31) - 1;
vector<vector<int>> dp(501, vector<int>(501, num));
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> c[i];
	}
	for (int i = 0; i <= n; i++)dp[i][i] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j + i <= n; j++) {
			int s = j;
			int e = j + i;
			for (int k = s; k < e; k++) {
				dp[s][e] = min(dp[s][e],dp[s][k] + dp[k + 1][e] + r[s] * c[k] * c[e]);
			}
		}
	}
	cout << dp[1][n];
}