#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int R, C;
vector<string> board;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
typedef pair<int, int> pii;
pii s;
queue<pii> fire;

int bfs() {
	queue<pii> q;
	q.push(s);
	int time = 0;

	while (!q.empty()) {
		int size = q.size();
		time++;
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (board[x][y] == 'F')continue;

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
					return time;
				}
				if (board[nx][ny] != '.')continue;
				q.push({ nx,ny });
				board[nx][ny] = 'J';
			}
		}

		size = fire.size();

		for (int i = 0; i < size; i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C || board[nx][ny] == '#' || board[nx][ny] == 'F')continue;
				board[nx][ny] = 'F';
				fire.push({ nx,ny });
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	board.resize(R);

	for (int i = 0; i < R; i++) {
		cin >> board[i];

		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'J')s = { i,j };
			if (board[i][j] == 'F')fire.push({ i,j });
		}
	}

	int answer = bfs();

	if (!answer)cout << "IMPOSSIBLE";
	else cout << answer;
}