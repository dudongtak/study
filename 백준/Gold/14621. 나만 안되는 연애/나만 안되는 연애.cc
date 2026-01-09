#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int n, m;
vector<char> s_type;
typedef pair<int, int> pii;
vector<vector<pii>> board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	s_type.resize(n);
	board.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> s_type[i];
	}

	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		if (s_type[u] == s_type[v])continue;
		board[u].push_back({ v,d });
		board[v].push_back({ u,d });
	}
	priority_queue<pii, vector<pii>, greater<>> pq;
	vector<bool> visit(n, false);
	int Min = 0, cnt = 0;
	pq.push({ 0,0 });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (visit[cur])continue;
		cnt++;
		visit[cur] = true;
		Min += w;

		for (auto next : board[cur]) {
			int node = next.first;
			int next_w = next.second;
			if (visit[node])continue;
			pq.push({ next_w,node });
		}
	}
	if (cnt == n)cout << Min;
	else cout << -1;
}