#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll N, X;
vector<ll> p;
vector<ll> s;

ll eat(ll l, ll n) {
	if (l == 0)return 1;
	if (n <= 1)return 0;
	else if (n <= 1 + s[l - 1])return eat(l - 1, n - 1);
	else if (n == 2 + s[l - 1])return p[l - 1] + 1;//중간까지 먹을때
	else if (n <= 2 + s[l - 1] * 2)return p[l - 1] + 1 + eat(l - 1, n - 2 - s[l - 1]);
	else return p[l - 1] * 2 + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> X;

	p.resize(N + 1);
	s.resize(N + 1);

	p[0] = 1;
	s[0] = 1;

	for (int i = 1; i <= N; i++) {
		p[i] = p[i - 1] * 2 + 1;
		s[i] = s[i - 1] * 2 + 3;
	}

	cout << eat(N, X);
}