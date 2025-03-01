#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
vector<vector<char>> map(1001, vector<char>(1001, '0'));
vector<vector<int>> dp(1001, vector<int>(1001, 0));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			map[i][j] = str[j - 1];
		}
	}

	int Max = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '1') {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
				Max = max(Max, dp[i][j]);
			}
			else dp[i][j] = 0;
		}
	}

	cout << Max * Max;
}