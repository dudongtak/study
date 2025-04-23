#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> board(10, vector<int>(10));
int answer[2] = { 0,0 };
vector<int> l(100, 0);
vector<int> r(100, 0);

void dfs(int row, int col, int cnt, int color) {
	if (col >= N) {
		row++;
		if (col % 2 == 0)col = 1;
		else col = 0;
	}
	if (row >= N) {
		answer[color] = max(answer[color], cnt);
		return;
	}

	if (board[row][col] && !l[col - row + N - 1] && !r[row + col]) {
		l[col - row + N - 1] = r[row + col] = 1;
		dfs(row, col + 2, cnt + 1, color);
		l[col - row + N - 1] = r[row + col] = 0;
	}
	dfs(row, col + 2, cnt, color);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0, 0);
	dfs(0, 1, 0, 1);

	cout << answer[0] + answer[1];
}