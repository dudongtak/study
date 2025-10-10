#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
vector<vector<int>> board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	board.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> board[i][j];

	long long answer = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<bool> visit(N, false);
	pq.push({ 0,0 });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (visit[cur])continue;
		answer += w;
		visit[cur] = true;

		for (int i = 0; i < N; i++) {
			if (i == cur || visit[i])continue;
			pq.push({ board[cur][i],i });
		}
	}

	cout << answer;
}