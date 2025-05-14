#include<iostream>
#include<vector>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int answer = 0;
int R, C, T;
typedef struct purifier {
	int u = -1;
	int d = -1;
}purifier;
purifier p;
vector<vector<int>> board(52, vector<int>(52, -1));

void diffuse() {
	vector<vector<int>> tmp(R + 2, vector<int>(C + 2, 0));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == 0)continue;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 1 || nx > R)continue;
				if (ny < 1 || ny > C)continue;
				if (board[nx][ny] == -1)continue;
				cnt++;
				tmp[nx][ny] += board[i][j] / 5;
			}

			tmp[i][j] -= board[i][j] / 5 * cnt;
		}
	}

	for (int i = 1; i <= R; i++)for (int j = 1; j <= C; j++)board[i][j] += tmp[i][j];
}

void rotate() {
	vector<vector<int>> tmp = board;

	int x = p.u;
	int y = 2;
	for (int i = C + 1; i > y; i--) {
		tmp[x][i] = board[x][i - 1];
	}
	tmp[x][2] = 0;

	y = C;
	for (int i = 0; i < x; i++) {
		tmp[i][y] = board[i + 1][y];
	}

	x = 1;
	for (int i = 0; i < y; i++) {
		tmp[x][i] = board[x][i + 1];
	}

	y = 1;
	for (int i = p.u-1; i > 1; i--) {
		tmp[i][y] = board[i - 1][y];
	}

	x = p.d;
	y = 2;
	for (int i = C + 1; i > y; i--) {
		tmp[x][i] = board[x][i - 1];
	}
	tmp[x][2] = 0;

	y = C;
	for (int i = R + 1; i > x; i--) {
		tmp[i][y] = board[i - 1][y];
	}

	x = R;
	for (int i = 0; i < y; i++) {
		tmp[x][i] = board[x][i + 1];
	}
	
	y = 1;
	for (int i = p.d + 1; i < R; i++) {
		tmp[i][y] = board[i + 1][y];
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == -1)continue;
			board[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++)for (int j = 1; j <= C; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == -1) {
			if (p.u == -1) p.u = i;
			else p.d = i;
		}
	}


	while (T--) {
		diffuse();

		rotate();
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == -1)continue;
			answer += board[i][j];
		}
	}

	cout << answer;
}