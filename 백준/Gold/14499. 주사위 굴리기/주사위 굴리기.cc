#include<iostream>
#include<vector>
using namespace std;

int dice[] = { 0,0,0,0,0,0 };
int N, M, x, y, K;
vector<vector<int>> board(20, vector<int>(20, -1));
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> board[i][j];

	int cur = 0;

	while (K--) {
		int op;
		cin >> op;
		x += dx[op];
		y += dy[op];

		if (x < 0 || y < 0 || x >= N || y >= M) {
			x -= dx[op];
			y -= dy[op];
			continue;
		}

		int tmp = dice[0];
		if (op == 1) {
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = tmp;
		}
		else if (op == 2) {
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
		}
		else if (op == 3) {
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
		}
		else if (op == 4) {
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
		}

		if (board[x][y] == 0) {
			board[x][y] = dice[0];
		}
		else {
			dice[0] = board[x][y];
			board[x][y] = 0;
		}

		cout << dice[5] << "\n";
	}
}