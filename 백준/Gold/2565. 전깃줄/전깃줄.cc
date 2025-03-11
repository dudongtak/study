#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx1, idx2;
		cin >> idx1 >> idx2;
		vec.push_back({ idx1,idx2 });
	}

	sort(vec.begin(), vec.end());

	vector<int> dp(n, 0);

	int Max = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (vec[j].second < vec[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		Max = max(dp[i], Max);
	}

	cout << n - Max;
}