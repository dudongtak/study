#include<iostream>
#include<vector>
using namespace std;

int N, H;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> H;

	vector<int> bottom(H + 1, 0);
	vector<int> top(H + 1, 0);
	vector<int> res(H + 1, 0);

	for (int i = 0; i < N / 2; i++) {
		int t, b;
		cin >> b >> t;
		bottom[b]++;
		top[H + 1 - t]++;
	}

	for (int i = H - 1; i >= 1; i--)bottom[i] += bottom[i + 1];

	int Min = 2000000000;
	int cnt = 0;

	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		res[i] += top[i] + bottom[i];
		if (Min > res[i]) {
			cnt = 1;
			Min = res[i];
		}
		else if (res[i] == Min)cnt++;
	}

	cout << Min << " " << cnt;
}