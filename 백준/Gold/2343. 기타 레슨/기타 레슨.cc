#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> study;
int sum = 0;
int answer = 1e9;

bool check(int size) {
	vector<int> blueray;
	int s = 0, size_sum = 0;
	for (int i = 0; i < n; i++) {
		s += study[i];
		if (s > size) {
			s -= study[i];
			if(s<=size)blueray.push_back(s);
			s = study[i];
		}
	}
	if (s <= size)blueray.push_back(s);
	for (int i = 0; i < blueray.size(); i++)size_sum += blueray[i];
	return blueray.size() <= m && size_sum == sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	study.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> study[i];
		sum += study[i];
	}

	int s = 0, e = sum, m;
	while (s <= e) {
		m = (s + e) / 2;

		if (check(m)) {
			e = m - 1;
			answer = min(answer, m);
		}
		else s = m + 1;
	}
	cout << answer;
}