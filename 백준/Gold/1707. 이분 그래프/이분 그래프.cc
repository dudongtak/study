#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int n, vector<vector<int>> &map, vector<int> &b) {
	queue<int> q;
	q.push(n);

	b[n] = 1;

	while (!q.empty()) {
		int s = q.front();
		q.pop();

		for (int i = 0; i < map[s].size(); i++) {
			if (b[s] == b[map[s][i]]) {
				return false;
			}
			if (b[map[s][i]] == -1) {
				q.push(map[s][i]);
				b[map[s][i]] = 1 - b[s];
			}
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int v, e;
		cin >> v >> e;
		vector<vector<int>> map(v);
		vector<int> bip(v, -1);

		for (int j = 0; j < e; j++) {
			int s, ed;
			cin >> s >> ed;
			map[s - 1].push_back(ed - 1);
			map[ed - 1].push_back(s - 1);
		}
		bool check = true;

		for (int i = 0; i < v; i++) {
			if (bip[i] == -1) {
				if (check != bfs(i, map, bip)) {
					check = false;
					break;
				}
			}
		}
		cout << (check ? "YES" : "NO") << "\n";
	}
}