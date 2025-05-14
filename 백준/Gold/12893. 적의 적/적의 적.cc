#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, a, b;
vector<int> r(1000001, 0);
vector<vector<int>> p(2001);

bool bfs(int s) {
	r[s] = 1;
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < p[cur].size(); i++) {
			int next = p[cur][i];

			if ((r[cur] == 1 && r[next] == 1) || (r[cur] == 2 && r[next] == 2))return false;
			if (r[next] == 0) {
				if (r[cur] == 1)r[next] = 2;
				else r[next] = 1;
				q.push(next);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (r[i] != 0)continue;
		if (!bfs(i)) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}