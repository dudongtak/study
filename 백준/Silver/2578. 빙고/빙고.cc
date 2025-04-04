#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> board(5, vector<int>(5));
map<int, pair<int, int>> m;

bool check() {
	int l_cnt = 0;
	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == -1)cnt++;
		}
		if (cnt == 5)l_cnt++;
	}
	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (board[j][i] == -1)cnt++;
		}
		if (cnt == 5)l_cnt++;
	}
	if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1)l_cnt++;

	if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)l_cnt++;

	if (l_cnt >= 3)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			m[board[i][j]] = { i,j };
		}
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cnt++;
			int num;
			cin >> num;
			int x = m[num].first;
			int y = m[num].second;
			board[x][y] = -1;
			if (check()) {
				cout << cnt;
				return 0;
			}
		}
	}
}