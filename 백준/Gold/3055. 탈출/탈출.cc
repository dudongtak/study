#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int R, C;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
typedef pair<int, int> pii;
queue<pii> water;
queue<pii> Ss;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	vector<vector<char>> board(R, vector<char>(C));
	vector<vector<bool>> visit(R, vector<bool>(C, false));

	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++) {
		cin >> board[i][j];
		if (board[i][j] == 'S') {
			Ss.push({ i,j });
			visit[i][j] = true;
		}
		if (board[i][j] == '*')water.push({ i,j });
	}

	int cnt = 0;
	bool flag = false;

	while (true) {
		cnt++;
		int qsize = water.size();

		while (qsize--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx<0 || ny<0 || nx>=R || ny>=C || board[nx][ny] != '.')continue;
				board[nx][ny] = '*';
				water.push({ nx,ny });
			}
		}

		qsize = Ss.size();

		while (qsize--) {
			int x = Ss.front().first;
			int y = Ss.front().second;
			Ss.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx<0 || ny<0 || nx>=R || ny>=C || visit[nx][ny])continue;
				if (board[nx][ny] == 'D') {
					cout << cnt << '\n';
					return 0;
				}
				if (board[nx][ny] == '.') {
					visit[nx][ny] = true;
					Ss.push({ nx,ny });
				}
			}
		}
		if (Ss.size() == 0)break;
	}

	cout << "KAKTUS";
}