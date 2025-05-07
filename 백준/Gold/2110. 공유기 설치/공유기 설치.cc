#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C;
vector<long long> h;
long long Max = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	h.resize(N);

	for (int i = 0; i < N; i++)cin >> h[i];

	sort(h.begin(), h.end());

	if (N == 2) {
		cout << h[N - 1] - h[0];
		return 0;
	}

	long long s = 1;
	long long e = h[N - 1] - h[0];

	while (s <= e) {

		long long m = (s + e) / 2;
		int start = h[0];
		int cnt = 1;

		for (int i = 1; i < N; i++) {
			if (h[i] - start >= m) {
				cnt++;
				start = h[i];
			}
		}

		if (cnt >= C) {
			Max = max(Max, m);
			s = m + 1;
		}
		else e = m - 1;
	}
	cout << Max;
}