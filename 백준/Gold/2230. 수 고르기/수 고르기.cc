#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<ll> arr(N);

	for (int i = 0; i < N; i++)cin >> arr[i];

	sort(arr.begin(), arr.end());

	int s = 0, e = 0;

	ll answer = 2000000001;

	while (s < N&&e < N) {
		ll diff = arr[e] - arr[s];
		if (diff < M)e++;
		else {
			answer = min(answer, diff);
			s++;
		}
	}

	cout << answer;
}