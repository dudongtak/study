#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, K;
vector<vector<int>> step(1000001);
vector<int> dis(1000001, 100000000);

void bfs() {
	queue<int> q;
	vector<bool> visit(N + 1, false);
	q.push(0);
	visit[0] = true;
	dis[0] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < step[cur].size(); i++) {
			int next = step[cur][i];
			if (visit[next])continue;
			dis[next] = min(dis[next], dis[cur] + 1);
			visit[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int next1 = i + 1;
		int next2 = i + i / 2;
		if (next1 <= N)step[i].push_back(next1);
		if (next2 <= N)step[i].push_back(next2);
	}


	bfs();
	if (dis[N] <= K)cout << "minigimbob";
	else cout << "water";
}