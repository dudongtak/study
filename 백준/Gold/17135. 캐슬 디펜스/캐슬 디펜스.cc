#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, D;
vector<vector<int>> board;
int Max = -1;
typedef pair<int, int> pii;

typedef struct target {
	int x, y, d;
}target;

int getDist(pii a,pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool cmp(target &a, target &b) {
	if (a.d == b.d)return a.y < b.y;
	return a.d < b.d;
}

int check(vector<int> a) {
	vector<vector<int>> copyBoard = board;
	int kill = 0;

	int row = N;
	while (row > 0) {
		vector<pii> enemy;
		for (int i = 0; i < 3; i++) {
			vector<target> ts;
			pii archer = { row,a[i] };
			for (int x = 0; x < row; x++) {
				for (int y = 0; y < M; y++) {
					if (copyBoard[x][y] == 0)continue;
					pii e = { x,y };
					int d = getDist(archer, e);
					if (d > D)continue;
					ts.push_back({ x,y,d });
				}
			}
			if (ts.empty())continue;
			sort(ts.begin(), ts.end(), cmp);
			enemy.push_back({ ts[0].x,ts[0].y });
		}
		for (int i = 0; i < enemy.size(); i++) {
			if (copyBoard[enemy[i].first][enemy[i].second] == 1) {
				kill++;
				copyBoard[enemy[i].first][enemy[i].second] = 0;
			}
		}
		row--;
	}
	return kill;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> D;

	board.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> board[i][j];
	
	vector<bool> tmp(M, false);
	tmp[0] = true;
	tmp[1] = true;
	tmp[2] = true;

	do {
		vector<int> archer;
		for (int i = 0; i < M; i++)if (tmp[i])archer.push_back(i);
		Max = max(Max, check(archer));
	} while (prev_permutation(tmp.begin(), tmp.end()));

	cout << Max;
}