#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> idx(100001, -1);
vector<int> in(100001, -1);
vector<int> post(100001, -1);

void pre(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe)return;

	int root = idx[post[pe]];
	int left = root - is;
	int right = ie - root;

	cout << in[root] << " ";

	pre(is, root - 1, ps, ps + left - 1);
	pre(root + 1, ie, ps + left, pe - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (int i = 1; i <= N; i++)cin >> post[i];

	pre(1, N, 1, N);
}