#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1e9
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int hx[] = { 2,2,1,1,-1,-1,-2,-2 };
int hy[] = { 1,-1,2,-2,2,-2,1,-1 };
typedef pair<int, int> pii;
int k, w, h;
vector<vector<int>> board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> w >> h;

	board.resize(h, vector<int>(w));
	vector<vector<vector<int>>> dis(h, vector<vector<int>>(w, vector<int>(31,INF)));
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)cin >> board[i][j];

	dis[0][0][k] = 0;
	queue<pair<pii,int>> q;
	q.push({ { 0,0 } ,k });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int ny = y + hy[i];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w || board[nx][ny] == 1)continue;
				if (dis[nx][ny][cnt - 1] > dis[x][y][cnt] + 1) {
					dis[nx][ny][cnt - 1] = dis[x][y][cnt] + 1;
					q.push({ {nx,ny},cnt - 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w || board[nx][ny] == 1)continue;
			if (dis[nx][ny][cnt] > dis[x][y][cnt] + 1) {
				dis[nx][ny][cnt] = dis[x][y][cnt] + 1;
				q.push({ {nx,ny},cnt});
			}
		}
	}

	int answer = INF;
	for (int i = 0; i <= k; i++)answer = min(answer, dis[h - 1][w - 1][i]);
	if (answer == INF)cout << -1;
	else cout << answer;
}