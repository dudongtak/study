#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, f, s;
vector<vector<int>> info(32000);
vector<int> Rank;
//rank idx

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	Rank.resize(N);

	for (int i = 0; i < N; i++)Rank[i] = 0;

	for (int i = 0; i < M; i++) {
		cin >> f >> s;
		info[f - 1].push_back(s - 1);

		Rank[s - 1]++;
	}

	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < N; i++)if (Rank[i] == 0)pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur + 1 << " ";

		for (int i = 0; i < info[cur].size(); i++) {
			int next = info[cur][i];
			Rank[next]--;
			if (Rank[next] == 0)pq.push(next);
		}
	}
}