#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
vector<int> dp(1000001, 0);

vector<int> getSet(string s) {
	vector<int> res;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')continue;
		string tmp;
		for (int j = i; j < s.size(); j++) {
			tmp.push_back(s[j]);
			if (s != tmp)res.push_back(stoi(tmp));
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	if (N < 10) {
		cout << -1;
	}
	else {
		for (int i = 10; i <= N; i++) {
			vector<int> v = getSet(to_string(i));

			int x = 1000001;
			for (int j = 0; j < v.size(); j++) {
				if (dp[i - v[j]] == 0) {
					x = min(x, v[j]);
				}
			}

			if (x != 1000001)dp[i] = x;
		}

		if (dp[N] == 0)cout << -1;
		else cout << dp[N];
	}
}