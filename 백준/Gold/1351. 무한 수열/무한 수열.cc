#include<iostream>
#include<map>
using namespace std;

long long n, p, q;
map<long long, long long> m;

long long dfs(long long i) {
	if (m[i] != 0)return m[i];
	return m[i] = dfs(i / p) + dfs(i / q);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> q;

	m[0] = 1;
	m[1] = 2;
	dfs(n);

	cout << m[n];
}