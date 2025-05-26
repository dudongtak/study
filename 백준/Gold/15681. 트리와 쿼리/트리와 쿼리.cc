#include<vector>
#include<iostream>
using namespace std;

int N, R, Q, U, V;
vector<vector<int>> nodes;
vector<bool> visit(100001, false);
vector<int> subtree;

int dfs(int child,int parent) {
	subtree[child] = 1;
	for (int i = 0; i < nodes[child].size(); i++) {
		int next = nodes[child][i];
		if (next != parent) {
			subtree[child] += dfs(next, child);
		}
	}
	return subtree[child];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> R >> Q;

	nodes.resize(N + 1);
	subtree.resize(N + 1, 0);

	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		nodes[U].push_back(V);
		nodes[V].push_back(U);
	}

	dfs(R, 0);

	while (Q--) {
		cin >> U;
		cout << subtree[U] << '\n';
	}
}