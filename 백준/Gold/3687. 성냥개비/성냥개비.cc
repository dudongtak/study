#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;

int T, cnt;
vector<long long> dp(101, LLONG_MAX);
int num[8] = { 0,0,1,7,4,2,0,8 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 9;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;

	for (int i = 8; i <= 100; i++) {
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
		}
	}

	cin >> T;

	while (T--) {
		cin >> cnt;

		cout << dp[cnt] << " ";
		string str;

		while (cnt > 0) {
			if (cnt == 3) {
				str.push_back('7');
				cnt -= 3;
			}
			else {
				cnt -= 2;
				str.push_back('1');
			}
		}
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}
}