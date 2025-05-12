#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> dev;
int Max = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dev.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> dev[i];
	}

	int s = 0, e = N - 1;
	while (s < e) {
		Max = max(Max, (e - s - 1)*min(dev[s], dev[e]));

		if (dev[s] < dev[e])s++;
		else e--;
	}

	cout << Max;
}