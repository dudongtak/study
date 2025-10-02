#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

typedef pair<int, int> pii;
typedef struct coord {
	pii lu, rd;
}coord;
int N, M, K, r, c, s;
vector<coord> coords;
vector<bool> visit;
int Min = 5001;

void rotate(vector<vector<int>> &b, int sx, int sy, int ex, int ey) {
	if (sx > ex)return;
	if (sy > ey)return;

	while (sx < ex&&sy < ey) {
		vector<int> tmp;
		for (int j = sy; j < ey; j++) tmp.push_back(b[sx][j]);
		for (int i = sx; i < ex; i++) tmp.push_back(b[i][ey]);
		for (int j = ey; j > sy; j--) tmp.push_back(b[ex][j]);
		for (int i = ex; i > sx; i--) tmp.push_back(b[i][sy]);

		rotate(tmp.rbegin(), tmp.rbegin() + 1, tmp.rend());

		int idx = 0;
		for (int j = sy; j < ey; j++) b[sx][j] = tmp[idx++];
		for (int i = sx; i < ex; i++) b[i][ey] = tmp[idx++];
		for (int j = ey; j > sy; j--) b[ex][j] = tmp[idx++];
		for (int i = ex; i > sx; i--) b[i][sy] = tmp[idx++];
		sx++; sy++; ex--; ey--;
	}
}

void dfs(int cnt,vector<vector<int>> b) {
	if (cnt == K) {
		for (int i = 0; i < N; i++)Min = min(Min, accumulate(b[i].begin(), b[i].end(), 0));
		return;
	}
	
	for (int i = 0; i < K; i++) {
		if (visit[i])continue;
		vector<vector<int>> temp = b;
		rotate(temp, coords[i].lu.first, coords[i].lu.second, coords[i].rd.first, coords[i].rd.second);

		visit[i] = true;
		dfs(cnt + 1, temp);
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	vector<vector<int>> board(N, vector<int>(M));
	visit.resize(K, false);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> board[i][j];

	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		coords.push_back({ { r - s - 1,c - s - 1 }, { r + s - 1,c + s - 1 } });
	}

	dfs(0, board);

	cout << Min;
}