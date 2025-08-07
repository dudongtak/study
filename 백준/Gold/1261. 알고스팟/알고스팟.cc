#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> board(100, vector<int>(100, -1));
vector<vector<int>> dis(100, vector<int>(100, 100000));
typedef pair<int, int> pii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			board[i][j] = str[j] - '0';
		}
	}
	
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
	pq.push({ 0,{0,0} });
	dis[0][0] = 0;

	while (!pq.empty()) {
		pii cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (dis[cur.first][cur.second] < w)continue;
		dis[cur.first][cur.second] = w;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
			int nw = w + board[nx][ny];

			if (nw < dis[nx][ny]) {
				dis[nx][ny] = nw;
				pq.push({ nw,{nx,ny} });
			}
		}
	}

	cout << dis[M - 1][N - 1];
}