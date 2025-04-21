#include<iostream>
#include<vector>
using namespace std;

int N, p;
typedef struct node {
	int data = -1;
	vector<node*> c;
}node;

int cnt = 0;

void dfs(int p, node *n) {
	if (n->data == p)return;

	if (n->c.size() == 0) {
		cnt++; return;
	}
	if (n->c.size() == 1 &&n->c[0]->data==p) {
		cnt++; return;
	}

	for (int i = 0; i < n->c.size(); i++) {
		dfs(p, n->c[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<node> narr(N);

	for (int i = 0; i < N; i++) {
		node n;
		n.data = i;
		narr[i] = n;
	}

	node *tree=NULL;

	for (int i = 0; i < N; i++) {
		cin >> p;
		if (p == -1) {
			tree = &narr[i];
		}
		else {
			narr[p].c.push_back(&narr[i]);
		}
	}
	cin >> p;
	if (p == tree->data) {
		cout << 0; return 0;
	}
	dfs(p, tree);
	cout << cnt;
}