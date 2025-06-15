#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	string answer;
	int i = str1.size(), j = str2.size();
	while (!(i == 0 || j == 0)) {
		if (dp[i][j] == dp[i - 1][j])i--;
		else if (dp[i][j] == dp[i][j - 1])j--;
		else {
			i--; j--;
			answer.push_back(str1[i]);
		}
	}
	reverse(answer.begin(), answer.end());
	cout << dp[str1.size()][str2.size()] << "\n" << answer;
}