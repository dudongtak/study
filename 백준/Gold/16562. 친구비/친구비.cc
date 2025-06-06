#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K, cost;
vector<int> student(10000, 1000001);
vector<int> arr;
vector<bool> check;

int Find(int v) {
	if (v == arr[v])return v;
	return arr[v] = Find(arr[v]);
}

void Union(int a, int b) {
	arr[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	arr.resize(N);
	check.resize(N);
	cost = K;

	for (int i = 0; i < N; i++){
		cin >> student[i];
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a = Find(a - 1);
		b = Find(b - 1);
		if (student[a] < student[b])swap(a, b);
		Union(a, b);
	}

	for (int i = 0; i < N; i++) {
		if (cost < 0) {
			cout << "Oh no";
			return 0;
		}
		int idx = Find(i);
		if (check[idx])continue;
		cost -= student[idx];
		check[idx] = true;
	}

	if (K - cost < 0)cout << "Oh no";
	else cout << K-cost;
}