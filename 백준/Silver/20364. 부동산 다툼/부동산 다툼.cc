#include<iostream>
#include<vector>
using namespace std;

int N, Q, idx, node;
int INF = 1048576 + 1;
vector<bool> tree(INF, false);

void find_node(int idx) {
	if (tree[idx])node = idx;
	if (idx == 1)return;
	find_node(idx / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> idx;
		node = 0;
		find_node(idx);
		if (node == 0)tree[idx] = true;
		cout << node << "\n";
	}
}