#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<char>> map;
string str;
typedef pair<int, int> pii;
vector<pii> land;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int x, int y) {
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	visit[x][y] = true;
	queue<pii> q;
	q.push({ x,y });
	int Max = 0;
	vector<vector<int>> dis(N, vector<int>(M, 0));

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 'W' || visit[nx][ny])continue;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			Max = max(Max, dis[nx][ny]);
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	return Max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'L')land.push_back({ i,j });
		}
	}

	int answer = 0;
	for (int i = 0; i < land.size(); i++)answer = max(answer, bfs(land[i].first, land[i].second));

	cout << answer;
}