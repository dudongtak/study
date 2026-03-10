#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> zero;
vector<vector<int>> board(9, vector<int>(9, 0));

bool check(int x,int y,int num) {
	for (int i = 0; i < 9; i++)if (board[x][i] == num || board[i][y] == num)return false;

	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;

	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (board[sx + i][sy + j] == num)return false;
	
	return true;
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)cout << board[i][j] << " ";
		cout << '\n';
	}
}

void dfs(int depth) {
	if (depth == zero.size()) {
		print();
		exit(0);
	}
	int x = zero[depth].first;
	int y = zero[depth].second;

	for (int i = 1; i < 10; i++) {
		if (!check(x, y, i))continue;
		board[x][y] = i;
		dfs(depth + 1);
		board[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)for (int j = 0; j < 9; j++) {
		cin >> board[i][j];
		if (board[i][j] == 0)zero.push_back({ i,j });
	}
	dfs(0);
}