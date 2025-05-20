#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	vector<int> rank(N, 0), num(N, 0), result(N, 0);
	vector<vector<int>> s(N);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		s[A - 1].push_back(B - 1);
		num[B - 1]++;
		rank[B - 1]++;
	}

	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (rank[i] == 0) {
			q.push(i);
			result[i] = num[i] + 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < s[cur].size(); i++) {
			int next = s[cur][i];
			rank[next]--;

			result[next] = max(result[next], result[cur] + 1);
			if (rank[next] == 0)q.push(next);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}