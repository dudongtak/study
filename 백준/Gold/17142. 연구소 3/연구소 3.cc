#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<vector<int>> board(50, vector<int>(50, -1));
typedef pair<int, int> pii;
vector<pii> virus;
int remain = 0;
int Min = 25001;

int bfs(vector<pii> s) {
	vector<vector<int>> dis(N, vector<int>(N, -1));
	queue<pii> q;

	int tmp = remain;

	for (int i = 0; i < s.size(); i++) {
		int x = s[i].first;
		int y = s[i].second;
		dis[x][y] = 0;
		q.push({ x,y });
	}

	int time = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1 || dis[nx][ny] != -1)continue;

			dis[nx][ny] = dis[x][y] + 1;
			q.push({ nx,ny });

			if (board[nx][ny] == 0) {
				time = max(time, dis[nx][ny]);
				if (--tmp == 0)return time;
			}
		}
	}
	if (remain == 0)return time;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)virus.push_back({ i,j });
			if (board[i][j] == 0)remain++;
		}
	}

	vector<bool> tmp(virus.size(), false);
	for (int i = 0; i < M; i++)tmp[i] = true;

	do {
		vector<pii> select;
		for (int i = 0; i < virus.size(); i++)if (tmp[i])select.push_back(virus[i]);

		int time = bfs(select);
		if (time != -1)Min = min(Min, time);
	} while (prev_permutation(tmp.begin(), tmp.end()));

	if (Min == 25001)cout << -1;
	else cout << Min;
}