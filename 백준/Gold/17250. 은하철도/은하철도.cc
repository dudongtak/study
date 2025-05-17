#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
int N, M;
vector<ll> mw;
vector<int> rail;

ll Find(int v) {
	if (rail[v] == v)return v;

	return rail[v] = Find(rail[v]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B)return;
	if (A > B) {
		mw[A] += mw[B];
		rail[B] = A;
	}
	else {
		mw[B] += mw[A];
		rail[A] = B;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	mw.resize(N);
	rail.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> mw[i];
		rail[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Union(a - 1, b - 1);

		int idx = Find(a - 1);

		cout << mw[idx] << "\n";
	}

}