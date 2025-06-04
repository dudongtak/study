#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int a, b, w;
vector<vector<pair<int, int>>> board(1000);
vector<vector<int>> dis(1000, vector<int>(1000, 100000000));

void bfs(int idx) {
	queue<int> q;
	dis[idx][idx] = 0;
	q.push(idx);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i].first;
			int d = board[cur][i].second;

			if (dis[idx][cur] + d < dis[idx][next]) {
				dis[idx][next] = dis[idx][cur] + d;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> w;
		board[a - 1].push_back({ b - 1,w });
		board[b - 1].push_back({ a - 1,w });
	}

	for (int i = 0; i < N; i++)bfs(i);

	while (M--) {
		cin >> a >> b;

		cout << dis[a - 1][b - 1] << "\n";
	}
}