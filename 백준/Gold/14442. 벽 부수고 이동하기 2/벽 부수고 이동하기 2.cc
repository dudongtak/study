#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#define INF 1e9
using namespace std;

int n, m, k;
vector<string> board;
typedef struct coord {
	int x, y, crash;
}coord;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	board.resize(n);
	for (int i = 0; i < n; i++)cin >> board[i];
	vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
	dis[0][0][0] = 1;
	queue<coord> q;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().crash;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (board[nx][ny] == '1') {
				if (c >= k)continue;
				if (dis[nx][ny][c + 1] > dis[x][y][c] + 1) {
					dis[nx][ny][c + 1] = dis[x][y][c] + 1;
					q.push({ nx,ny,c + 1 });
				}
			}
			else {
				if (dis[nx][ny][c] > dis[x][y][c] + 1) {
					dis[nx][ny][c] = dis[x][y][c] + 1;
					q.push({ nx,ny,c });
				}
			}
		}
	}
	int answer = INF;
	for (int i = 0; i <= k; i++)answer = min(answer, dis[n - 1][m - 1][i]);
	if (answer == INF)cout << -1;
	else cout << answer;
}