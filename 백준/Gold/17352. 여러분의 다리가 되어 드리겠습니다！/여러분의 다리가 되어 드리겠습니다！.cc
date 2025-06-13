#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N, s, e;
vector<int> arr;

int Find(int v) {
	if (v == arr[v])return v;
	return arr[v] = Find(arr[v]);
}

void Union(int a,int b) {
	int x = Find(a);
	int y = Find(b);

	arr[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)arr[i] = i;

	while (cin >> s >> e) {
		s--; e--;
		if (e < s) {
			Union(e, s);
		}
		else Union(s, e);
	}

	set<int> S;
	for (int i = 0; i < N; i++)S.insert(Find(i));

	for (auto num : S)cout << num + 1 << " ";
}