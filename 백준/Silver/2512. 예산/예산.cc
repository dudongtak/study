#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, budget, sum = 0, Max = 0, answer;
vector<int> city;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	city.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> city[i];
		sum += city[i];
		Max = max(Max, city[i]);
	}

	cin >> budget;

	if (budget >= sum) {
		cout << Max;
		return 0;
	}

	int s = 1, e = Max, m;
	while (s <= e) {
		m = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (m > city[i])sum += city[i];
			else sum += m;
		}

		if (budget >= sum) {
			s = m + 1;
			answer = m;
		}
		else if (budget < sum) e = m - 1;
	}

	cout << answer;
}