#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int Max, Min;
int cnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<vector<int>> board;

bool is_end() {
	Max = *max_element(board[0].begin(), board[0].end());
	Min = *min_element(board[0].begin(), board[0].end());
	return (Max - Min) <= k;
}

void make_flat() {
	vector<vector<int>> new_board = board;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == -1)continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n)continue;
				if (ny < 0 || ny >= n)continue;
				if (board[nx][ny] == -1)continue;
				new_board[i][j] += (board[nx][ny] - board[i][j]) / 5;
			}
		}
	}

	vector<int> flat;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_board[j][i] == -1)continue;
			else flat.push_back(new_board[j][i]);
		}
	}

	board = vector<vector<int>>(n, vector<int>(n, -1));
	board[0] = flat;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	board = vector<vector<int>>(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		cin >> board[0][i];
	}

	while (!is_end()) {
		cnt++;

		int ly = 1, lx = 1;
		int sy = 0;

		// 1. 물고기 추가
		Min = *min_element(board[0].begin(), board[0].end());
		for (int i = 0; i < n; i++) {
			if (board[0][i] == Min)board[0][i]++;
		}
		// 2. 어항 말기
		while (sy + lx + ly <= n) {
			for (int i = 0; i < lx; i++) {
				for (int j = 0; j < ly; j++) {
					int nx = ly - j;
					int ny = sy + i + ly;
					board[nx][ny] = board[i][j + sy];
					board[i][j + sy] = -1;
				}
			}
			sy += ly;
			if (ly == lx)lx++;
			else ly++;
		}
		

		// 3. 물고기 이동 및 평탄화
		make_flat();

		// 4. 중심을 기준으로 어항 2번 이동
		sy = 0;
		lx = 1;
		ly = n / 2;

		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < lx; i++) {
				for (int j = 0; j < ly; j++) {
					int nx = 2 * lx - i - 1;
					int ny = 2 * ly + sy - j - 1;
					board[nx][ny] = board[i][j + sy];
					board[i][j + sy] = -1;
				}
			}

			sy += ly;
			ly /= 2;
			lx *= 2;
		}

		make_flat();

	}

	cout << cnt;
}