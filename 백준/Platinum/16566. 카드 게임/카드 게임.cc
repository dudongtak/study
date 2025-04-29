#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, K, num;
vector<int> vec;

int Find(int v) {
	if (vec[v] == v)return v;
	return vec[v] = Find(vec[v]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A > B)vec[B] = A;
	else vec[A] = B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	vector<int> arr(M);

	for (int i = 0; i < M; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i <= M; i++)vec.push_back(i);

	for (int i = 0; i < K; i++) {
		cin >> num;
		int l = 0, r = M - 1;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (num >= arr[mid])l = mid + 1;
			else r = mid - 1;
		}
		l = Find(l);
		cout << arr[l] << "\n";
		Union(l, l + 1);
	}
}