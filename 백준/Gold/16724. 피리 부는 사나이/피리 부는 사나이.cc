#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N, M;
vector<vector<char>> board(1000, vector<char>(1000));
vector<vector<pair<int, int>>> c;
set<pair<int, int>> answer;

pair<int, int> Find(pair<int, int> p) {
	int x = p.first;
	int y = p.second;
	if (c[x][y] == p)return p;

	return c[x][y] = Find(c[x][y]);
}

void Union(pair<int, int> a, pair<int, int> b) {
	pair<int, int> x = Find(a);
	pair<int, int> y = Find(b);

	c[x.first][x.second] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	c.resize(N, vector<pair<int, int>>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			c[i][j] = { i,j };
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'D'&&i < N - 1)Union(c[i][j], c[i + 1][j]);
			if (board[i][j] == 'L'&&j > 0)Union(c[i][j], c[i][j - 1]);
			if (board[i][j] == 'U'&&i > 0)Union(c[i][j], c[i - 1][j]);
			if (board[i][j] == 'R'&&j < M - 1)Union(c[i][j], c[i][j + 1]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer.insert(Find({ i,j }));
		}
	}

	cout << answer.size();
}