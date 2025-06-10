#include<iostream>
#include<vector>
using namespace std;

int T, N;
typedef long long ll;
vector<ll> answer(1000001, 0);

void make_sum() {
	for (ll i = 1; i <= 1000000; i++) {
		for (ll j = i; j <= 1000000; j += i) {
			answer[j] += i;
		}
	}
	for (ll i = 1; i <= 1000000; i++) {
		answer[i] += answer[i - 1];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	
	make_sum();

	while (T--) {
		cin >> N;
		cout << answer[N] << "\n";
	}
}