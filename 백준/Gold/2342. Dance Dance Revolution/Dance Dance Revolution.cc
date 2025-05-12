#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w[5][5] = {
	{1,2,2,2,2},
{0,1,3,4,3},
{0,3,1,3,4},
{0,4,3,1,3},
{0,3,4,3,1}
};
int s = 1;
vector<int> Move(100001);
vector<vector<vector<int>>> dp(100001, vector<vector<int>>(5, vector<int>(5, 0)));

int dfs(int cur, int l, int r) {
	if (cur == s - 1)return 0;

	if (l != 0 && r != 0 && r == l)return 5000000;

	if (dp[cur][l][r] != 0)return dp[cur][l][r];

	return dp[cur][l][r] = min(dfs(cur + 1, Move[cur + 1], r) + w[l][Move[cur + 1]], dfs(cur + 1, l, Move[cur + 1]) + w[r][Move[cur + 1]]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	do {
		cin >> Move[s++];
	} while (Move[s - 1] != 0);


	cout << dfs(0, 0, 0);
}