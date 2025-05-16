#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N, M, H;
string s;
vector<vector<int>> p;
vector<vector<int>> dp(51, vector<int>(1001, 0));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i <= N; i++) {
		getline(cin, s);
		if (i == 0)continue;
		vector<int> arr;
		string tmp;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= '0'&&s[j] <= '9') {
				tmp.push_back(s[j]);
			}
			else {
				arr.push_back(stoi(tmp));
				tmp.clear();
			}
			if (j == s.size() - 1)arr.push_back(stoi(tmp));
		}
		p.push_back(arr);
	}

	for (int i = 0; i <= N; i++)dp[i][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			for (int k = 0; k < p[i-1].size(); k++) {
				if (j >= p[i - 1][k])dp[i][j] = (dp[i][j] + dp[i - 1][j - p[i - 1][k]]) % 10007;
			}
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[N][H];
}