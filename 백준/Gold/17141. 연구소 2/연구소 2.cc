#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> board;
typedef struct vi {
	int x, y;
}vi;
vector<vi> able;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int Min = 2501;

bool check(vector<vector<int>> &v) {
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (v[i][j] == 0)return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	board.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		cin >> board[i][j];
		if (board[i][j] == 2) {
			able.push_back({ i,j });
			board[i][j] = 0;
		}
	}

	int size = able.size();

	vector<bool> tmp(size, false);
	for (int j = 0; j < m; j++)tmp[j] = true;
	do {
		vector<vector<int>> copy = board;
		queue<vi> q;
		for (int j = 0; j < size; j++) {
			if (tmp[j]) {
				copy[able[j].x][able[j].y] = 2;
				q.push(able[j]);
			}
		}
		int cnt = 0;
		bool flag = true;
		while (!check(copy)) {
			cnt++;
			int qsize = q.size();
			if (qsize == 0) {
				flag = false;
				break;
			}
			for (int i = 0; i < qsize; i++) {
				vi cur = q.front();
				q.pop();

				for (int j = 0; j < 4; j++) {
					int nx = dx[j] + cur.x;
					int ny = dy[j] + cur.y;
					if (nx < 0 || ny < 0 || nx >= n || ny >= n||copy[nx][ny]!=0)continue;
					q.push({ nx,ny });
					copy[nx][ny] = 2;
				}
			}
		}
		if(flag)Min = min(Min, cnt);
	} while (prev_permutation(tmp.begin(), tmp.end()));

	if (Min == 2501)cout << -1;
	else cout << Min;
}