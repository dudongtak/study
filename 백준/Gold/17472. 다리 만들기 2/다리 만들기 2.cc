#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M, area;
vector<vector<int>> board;
vector<vector<int>> island_num;
vector<vector<bool>> visit;
vector<vector<int>> dis;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
typedef pair<int, int> pii;
vector<pii> v;
vector<vector<pii>> area_pos(51);

void bfs(int num, int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	visit[x][y] = true;
	island_num[x][y] = num;
	area_pos[num].push_back({ x,y });

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || board[nx][ny] == 0)continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
			island_num[nx][ny] = num;
			area_pos[num].push_back({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	board.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) {
		cin >> board[i][j];
		if (board[i][j] == 1)v.push_back({ i,j });
	}

	island_num = board;

	int num = 1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (!visit[x][y])bfs(num++, x, y);
	}
	dis.resize(num, vector<int>(num, 100));

	for (int i = 1; i < num; i++) {
		for (int j = 1; j < num; j++) {
			for (int k = 0; k < area_pos[i].size(); k++) {
				int x = area_pos[i][k].first;
				int y = area_pos[i][k].second;

				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					int len = 0;

					while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
						if (island_num[nx][ny] == i) break;
						if (island_num[nx][ny] > 0) {
							if (len >= 2) {
								int other = island_num[nx][ny];
								dis[i][other] = min(dis[i][other], len);
								dis[other][i] = min(dis[other][i], len);
							}
							break;
						}
						if (board[nx][ny] == 0) len++;
						nx += dx[dir];
						ny += dy[dir];
					}
				}
			}
		}
	}

	int answer = 0;
	int connected = 0;
	priority_queue<pii,vector<pii>,greater<>> pq;
	vector<bool> v_i(num, false);
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (v_i[cur])continue;
		v_i[cur] = true;
		answer += w;
		connected++;

		for (int i = 1; i < num; i++) {
			if (!v_i[i] && dis[cur][i] < 100) {
				pq.push({ dis[cur][i],i });
			}
		}
	}
	if(connected==num-1)cout << answer;
	else cout << -1;
}