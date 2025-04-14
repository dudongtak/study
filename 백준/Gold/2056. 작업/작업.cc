#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef vector<int> vi;
vi time(10001), dp(10001, 0), num(10001);
vector<vi> board(10001);
int N, res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> num[i];

		for (int j = 0; j < num[i]; j++) {
			int node;
			cin >> node;
			board[node].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (num[i] == 0) {
			q.push(i);
			dp[i] = time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res = max(res, dp[cur]);

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i];
			dp[next] = max(dp[next], dp[cur] + time[next]);
			if (--num[next] == 0)q.push(next);
		}
	}

	cout << res;
}