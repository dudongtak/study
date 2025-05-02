#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

int Find(int v,vector<int> &vec) {
	if (vec[v] == v)return v;
	return vec[v] = Find(vec[v], vec);
}

void Union(int a, int b, vector<int> &v, vector<bool> &c) {
	int A = Find(a, v);
	int B = Find(b, v);
	
	if (A == B) {
		c[A] = true;
	}
	else if (A > B) {
		v[B] = A;
		c[A] = c[A] || c[B];
	}
	else { 
		v[A] = B; 
		c[B] = c[A] || c[B];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int c = 1;
	while (N != 0 || M != 0) {
		vector<int> board(N + 1,0);
		vector<bool> cycle(N + 1, false);

		for (int i = 1; i <= N; i++) {
			board[i] = i;
		}

		int s, e;

		for (int i = 0; i < M; i++) {
			cin >> s >> e;
			Union(s, e, board,cycle);
		}
	

		int cnt = 0;
		
		for (int i = 1; i <= N; i++) {
			int root = Find(i, board);
			if (root == i && !cycle[i])cnt++;
		}

		cout << "Case " << c << ": ";
		if (cnt == 0) {
			cout << "No trees.\n";
		}
		else if (cnt == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << cnt << " trees.\n";
		}

		cin >> N >> M;
		c++;
	}
}