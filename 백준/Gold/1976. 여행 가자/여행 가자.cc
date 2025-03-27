#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int inf = 1000000;
int check;
vector<vector<int>> board(201);
vector<int> plan(1000);

bool bfs(int s, int e) {
	vector<int> visit(n + 1, 0);
	visit[s] = 1;
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i];
			if (next == e)return true;
			if (visit[next] == 0) {
				q.push(next);
				visit[next] = 1;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> check;
			if (check == 1) {
				board[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> plan[i];
	}

	int start = plan[0];
	for (int i = 1; i < m; i++) {
		if (start == plan[i])continue;
		if (!bfs(start, plan[i])) {
			cout << "NO";
			exit(0);
		}
		start = plan[i];
	}
	cout << "YES";
}