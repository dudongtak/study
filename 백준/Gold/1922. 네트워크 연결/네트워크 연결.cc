#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, a, b, c;
vector<vector<pair<int,int>>> network;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	network.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		network[a].push_back({ b,c });
		network[b].push_back({ a,c });
	}

	vector<bool> visit(N + 1, false);
	visit[1] = true;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	for (int i = 0; i < network[1].size(); i++) {
		pq.push({ network[1][i].second,network[1][i].first });
	}

	int answer = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (visit[cur])continue;

		answer += weight;
		visit[cur] = true;

		for (int i = 0; i < network[cur].size(); i++) {
			int nw = network[cur][i].second;
			int next = network[cur][i].first;

			if (visit[next])continue;
			pq.push({ nw,next });
		}
	}
	cout << answer;
}