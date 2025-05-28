#include<iostream>
#include<vector>
using namespace std;

vector<int> parent(51);

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, F;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) parent[i] = i;

	cin >> F;
	vector<int> knowsTruth;
	for (int i = 0; i < F; i++) {
		int num; cin >> num;
		knowsTruth.push_back(num);
	}

	vector<vector<int>> parties(M);
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		parties[i].resize(num);
		for (int j = 0; j < num; j++) {
			cin >> parties[i][j];
		}
		for (int j = 1; j < num; j++) {
			Union(parties[i][0], parties[i][j]);
		}
	}

	for (int t : knowsTruth) {
		Union(0, t);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool canLie = true;
		for (int x : parties[i]) {
			if (Find(x) == Find(0)) {
				canLie = false;
				break;
			}
		}
		if (canLie) cnt++;
	}
	cout << cnt << "\n";
}
