#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, X;
typedef pair<int, int> pii;
vector<vector<vector<pii>>> board(2,vector<vector<pii>>(1001));
vector<vector<int>> time(2);

void dijkstra(int s) {
	time[s][X] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,X });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int t = pq.top().first;
		pq.pop();

		if (t > time[s][cur])continue;

		for (int i = 0; i < board[s][cur].size(); i++) {
			int next = board[s][cur][i].first;
			int next_t = board[s][cur][i].second + t;

			if (next_t < time[s][next]) {
				time[s][next] = next_t;
				pq.push({ next_t,next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;
	time[0].resize(N + 1, 1000000001);
	time[1].resize(N + 1, 1000000001);

	for (int i = 0; i < M; i++) {
		int x, y, t;
		cin >> x >> y >> t;

		board[0][x].push_back({ y,t });
		board[1][y].push_back({ x,t });
	}

	dijkstra(0);
	dijkstra(1);

	int Max = -1;
	for (int i = 1; i <= N; i++)Max = max(Max, time[0][i] + time[1][i]);

	cout << Max;
}