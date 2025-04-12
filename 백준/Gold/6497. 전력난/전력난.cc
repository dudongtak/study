#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int M, N;
ll x, y, z;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> M >> N;
		if (M == 0 && N == 0)break;

		vector<vector<pll>> board(M);
		ll cost = 0;

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> z;
			board[x].push_back({ y,z });
			board[y].push_back({ x,z });
			cost += z;
		}

		priority_queue<pll, vector<pll>, greater<pll>> pq;
		vector<bool> visit(M, false);

		pq.push({ 0,0 });


		while (!pq.empty()) {
			ll cur = pq.top().second;
			ll weight = pq.top().first;
			pq.pop();

			if (visit[cur])continue;
			visit[cur] = true;
			cost -= weight;

			for (int i = 0; i < board[cur].size(); i++) {
				ll next = board[cur][i].first;
				ll next_weight = board[cur][i].second;
				if (!visit[next])pq.push({ next_weight,next });
			}
		}
		cout << cost << "\n";
	}
}