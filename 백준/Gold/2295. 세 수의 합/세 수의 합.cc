#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int N;
vector<int> u;
map<int, int> sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	u.resize(N);

	for (int i = 0; i < N; i++)cin >> u[i];

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum[u[i] + u[j]]++;
		}
	}

	sort(u.begin(), u.end());

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			int diff = u[i] - u[j];
			if (sum[diff] >= 1) {
				cout << u[i];
				return 0;
			}
		}
	}
}