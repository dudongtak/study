#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, T;
vector<int> chap;
vector<int> score;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> N >> T;

	chap.resize(N + 1);
	score.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> chap[i];
		cin >> score[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < T + 1; j++) {
			if (j >= chap[i])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - chap[i]] + score[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][T];
}