#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, r;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	vector<int> item(n);
	vector<vector<pii>> board(n);

	for (int i = 0; i < n; i++)cin >> item[i];

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		board[a - 1].push_back({ b - 1,l });
		board[b - 1].push_back({ a - 1,l });
	}

	int Max = -1;

	for (int i = 0; i < n; i++) {
		priority_queue<pii, vector<pii>, greater<>> pq;
		pq.push({ 0,i });
		vector<bool> visit(n, false);
		int items = 0;

		while (!pq.empty()) {
			int cur = pq.top().second;
			int w = pq.top().first;
			pq.pop();

			if (visit[cur])continue;
			visit[cur] = true;

			if (w > m)continue;
			items += item[cur];

			for (auto p : board[cur]) {
				int next_w = p.second + w;
				int next = p.first;
				if (visit[next])continue;
				pq.push({ next_w,next });
			}
		}
		Max = max(Max, items);
	}
	cout << Max;
}