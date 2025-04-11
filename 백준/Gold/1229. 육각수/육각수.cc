#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> hexagonal;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	hexagonal.push_back(1);

	int hexagonalNum = 0;
	int n = 1;
	while (true){
		hexagonalNum = 6 * n + hexagonal[n - 1] + 1 - 2 * n;
		if (hexagonalNum >= 1000000)break;
		hexagonal.push_back(hexagonalNum);
		n++;
	}
	vector<int> dp(1000001,6);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < hexagonal.size(); j++) {
			if (i < hexagonal[j])break;
			else {
				dp[i] = min(dp[i], dp[i - hexagonal[j]] + 1);
			}
		}
	}
	cout << dp[N];
}