#include<iostream>
#include<vector>
using namespace std;

int N, K;
vector<int> coin;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	
	coin.resize(N);

	for (int i = 0; i < N; i++)cin >> coin[i];

	for (int i = N - 1; i >= 0; i--) {
		int tmp = K / coin[i];
		if (tmp == 0)continue;

		cnt += tmp;
		K %= coin[i];
	}

	cout << cnt;
}