#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int n, m;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
vector<vector<pii>> board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	board.resize(n);

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		board[s - 1].push_back({ e - 1,v });
	}

	int s, e;
	cin >> s >> e;

	vector<ll> dis(n, INF);
	dis[s - 1] = 0;
	priority_queue<pli, vector<pli>, greater<>> pq;
	vector<int> prev(n, -1);
	pq.push({ 0,s - 1 });

	while (!pq.empty()) {
		ll w = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dis[cur] < w)continue;

		for (auto next : board[cur]) {
			int nextNode = next.first;
			ll nextW = w + next.second;
			if (nextW >= dis[nextNode])continue;
			prev[nextNode] = cur;
			dis[nextNode] = nextW;
			pq.push({ nextW,nextNode });
		}
	}
	int cnt = 0;
	vector<int> path;
	int node = e - 1;
	path.push_back(e);
	while (prev[node] != -1) {
		path.push_back(prev[node] + 1);
		node = prev[node];
	}
	cout << dis[e - 1] << "\n" << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; i--)cout << path[i] << " ";
}