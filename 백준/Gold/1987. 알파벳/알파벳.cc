#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C;
int Max = 0;
vector<vector<char>> board;
vector<bool> visit(26, false);
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int cnt, int x, int y) {
	Max = max(Max, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;

		char next = board[nx][ny];
		if (!visit[next - 'A']) {
			visit[next - 'A'] = true;
			dfs(cnt + 1, nx, ny);
			visit[next - 'A'] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C;

	board.resize(R);

	for (int i = 0; i < R; i++) {
		vector<char> row(C);
		for (int j = 0; j < C; j++) {
			cin >> row[j];
		}
		board[i] = row;
	}

	visit[board[0][0] - 'A'] = true;
	dfs(1, 0, 0);
	cout << Max;
}