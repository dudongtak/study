#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> board(9);
vector<pair<int, int>> blank;
bool solved = false;

bool can(int x, int y, char num) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == num) return false;
		if (board[i][y] == num) return false;
	}

	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}

	return true;
}

void dfs(int idx) {
	if (solved) return;

	if (idx == blank.size()) {
		solved = true;
		return;
	}

	int x = blank[idx].first;
	int y = blank[idx].second;

	for (char num = '1'; num <= '9'; num++) {
		if (!can(x, y, num)) continue;

		board[x][y] = num;
		dfs(idx + 1);

		if (solved) return;
		board[x][y] = '0';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		cin >> board[i];
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '0') {
				blank.push_back({ i, j });
			}
		}
	}

	dfs(0);

	for (int i = 0; i < 9; i++) {
		cout << board[i] << '\n';
	}

	return 0;
}