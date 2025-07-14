#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int M, N, H;
vector<vector<vector<int>>> board(100, vector<vector<int>>(100, vector<int>(100, -1)));
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

typedef struct coord {
	int x, y, z;
	coord(int Z, int X, int Y) :z(Z), x(X), y(Y) {}
}coord;
queue<coord> q;

int bfs() {
	while (!q.empty()) {
		coord cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];
			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (board[nz][nx][ny] == 0) {
				board[nz][nx][ny] = board[cur.z][cur.x][cur.y] + 1;
				q.push(coord(nz, nx, ny));
			}
		}
	}

	int res = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[i][j][k] == 0)return -1;
				res = max(res, board[i][j][k]);
			}
		}
	}
	return res - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push(coord(i, j, k));
				}
			}
		}
	}
	
	cout << bfs();
}