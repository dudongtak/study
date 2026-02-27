#include<iostream>
#include<queue>
using namespace std;

int n, k, p;
typedef long long ll;
vector<ll> prime;
priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	prime.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> prime[i];
		pq.push(prime[i]);
	}

	ll answer = 0;

	for (ll i = 0; i < k; i++) {
		answer = pq.top();
		pq.pop();

		for (ll j = 0; j < n; j++) {
			ll next = answer * prime[j];
			pq.push(next);
			if (answer%prime[j]==0)break;
		}
	}
	cout << answer;
}