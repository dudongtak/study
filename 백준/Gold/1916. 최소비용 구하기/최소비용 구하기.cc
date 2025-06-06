#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, a, b, w, s, e;
vector<vector<pair<int,int>>> board(1001);

int dijkstra(int s, int e) {
	vector<int> dis(N + 1, 100000000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<bool> v(N + 1, false);
	dis[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (v[cur])continue;
		v[cur] = true;

		if (cur == e)return d;

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i].first;
			int weight = board[cur][i].second;

			if (dis[next] > dis[cur] + weight) {
				dis[next] = dis[cur] + weight;
				pq.push({ dis[next],next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		board[a].push_back({ b,w });
	}

	cin >> s >> e;

	cout << dijkstra(s, e);
}