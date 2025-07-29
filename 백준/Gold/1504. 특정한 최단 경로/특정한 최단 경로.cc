#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, E;
typedef long long ll;
typedef pair<ll, int> pli;
vector<vector<pli>> board(801);
ll INF = 2000000001;
vector<vector<ll>> dis(3, vector<ll>(801, INF));
int m1, m2;

void dijkstra(int s, int cnt) {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({ 0,s });
	dis[cnt][s] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		ll w = pq.top().first;
		pq.pop();

		if (w > dis[cnt][cur])continue;

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i].first;
			ll next_w = w + board[cur][i].second;

			if (dis[cnt][next] > next_w) {
				dis[cnt][next] = next_w;
				pq.push({ next_w,next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b,c });
		board[b].push_back({ a,c });
	}

	cin >> m1 >> m2;

	dijkstra(1, 0);
	dijkstra(m1, 1);
	dijkstra(m2, 2);

	ll path1 = dis[0][m1] + dis[1][m2] + dis[2][N];
	ll path2 = dis[0][m2] + dis[2][m1] + dis[1][N];

	ll answer = path1 < path2 ? path1 : path2;
	if (answer >= INF)cout << -1;
	else cout << answer;
}