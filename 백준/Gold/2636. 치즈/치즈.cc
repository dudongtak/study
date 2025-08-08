#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> board;
typedef pair<int, int> pii;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool check() {
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)if (board[i][j] != 0)return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	board.resize(N + 2, vector<int>(M + 2, 0));

	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)cin >> board[i][j];

	int answer = 0;
	int cnt = 0;

	while (true) {
		if (check())break;

		vector<vector<int>> tmp = board;
		vector<vector<bool>> visit(N + 2, vector<bool>(M + 2, false));
		queue<pii> q;
		q.push({ 0,0 });
		visit[0][0] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx<0 || ny<0 || nx>N + 1 || ny>M + 1 || visit[nx][ny]) continue;
				visit[nx][ny] = true;

				if (board[nx][ny] == 0) {
					q.push({ nx,ny });
				}
				else {
					board[nx][ny] = 0;
				}
			}
		}
		answer++;
		if (check()) {
			for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)cnt += tmp[i][j];
			break;
		}
	}
	cout << answer << "\n" << cnt;
}