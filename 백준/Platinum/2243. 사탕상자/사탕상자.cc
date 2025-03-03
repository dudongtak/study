#include<iostream>
#include<vector>
using namespace std;

int n, op, r, c;
int Max = 1000005;
vector<int> candy_box(Max, 0);
vector<long long> tree(Max*4, 0);

int find(int node, int s, int e, int cnt) {
	if (s == e)return s;
	int m = (s + e) / 2;
	if (tree[node * 2] >= cnt)return find(node * 2, s, m, cnt);
	return find(node * 2 + 1, m + 1, e, cnt - tree[node * 2]);
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx<s || idx>e)return;
	tree[node] += diff;
	if (s != e) {
		int m = (s + e) / 2;
		update(node * 2, s, m, idx, diff);
		update(node * 2 + 1, m + 1, e, idx, diff);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	 
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> op >> r;
		if (op == 2) {
			cin >> c;
			candy_box[r] += c;
			update(1, 1, Max, r, c);
		}
		else {
			int idx = find(1, 1, Max, r);
			cout << idx << "\n";
			candy_box[idx]--;
			update(1, 1, Max, idx, -1);
		}
	}
}