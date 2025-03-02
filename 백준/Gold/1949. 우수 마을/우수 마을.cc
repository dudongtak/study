#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> tree(10001);
vector<vector<int>> dp(10001, vector<int>(2, 0)); 
vector<int> citizen(10001, 0);
vector<int> visit(10001, -1);

void dfs(int now) {
	visit[now] = 0;

	dp[now][0] = 0;
	dp[now][1] = citizen[now];

	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];

		if (visit[next] == 0)continue;
		
		dfs(next);

		dp[now][0] += max(dp[next][0], dp[next][1]);
		dp[now][1] += dp[next][0];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> citizen[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
}