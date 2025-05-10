#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> board(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, 0));
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int Max = 0;

int dfs(int x, int y) {
	if (dp[x][y])return dp[x][y];
	
	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N)continue;
		if (ny < 0 || ny >= N)continue;
		if (board[nx][ny] > board[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Max = max(Max, dfs(i, j));
	}
	cout << Max;
}