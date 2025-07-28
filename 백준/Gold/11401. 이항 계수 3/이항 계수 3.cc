#include<iostream>
using namespace std;

int N, K;
int DIV = 1000000007;
typedef long long ll;

ll power(ll a, ll b) {
	if (b == 0)return 1;

	ll tmp = power(a, b / 2) % DIV;
	if (b % 2 == 1)return tmp * tmp%DIV*a%DIV;
	return tmp * tmp%DIV;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (K == 1) {
		cout << N;
	}
	else if (K == 0 || N == K) {
		cout << 1;
	}
	else if (N - K == 1) {
		cout << N;
	}
	else {
		ll A = 1, B = 1, answer;
		for (int i = N; i >= N - K + 1; i--)A = (A*i) % DIV;
		for (int i = 1; i <= K; i++)B = (B*i) % DIV;
		answer = ((A%DIV)*power(B, DIV - 2) % DIV) % DIV;
		cout << answer;
	}
}