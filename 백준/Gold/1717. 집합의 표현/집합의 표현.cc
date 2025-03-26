#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, op, a, b;
vector<int> arr(1000001, -1);

int Find(int x) {
	if (x == arr[x])return x;
	return arr[x] = Find(arr[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)return;

	if (a < b)arr[b] = a;
	else arr[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)arr[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if (op == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b))cout << "YES\n";
			else cout << "NO\n";
		}
	}
}