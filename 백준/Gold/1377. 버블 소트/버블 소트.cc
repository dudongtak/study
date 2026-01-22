#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, a;

	cin >> N;
	vector<pii> A(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> a;
		A[i] = { a,i };
	}

	sort(A.begin(), A.end());

	int Max = -1;
	for (int i = 1; i <= N; i++) {
		Max = max(Max, A[i].second - i);
	}
	cout << Max + 1;
}