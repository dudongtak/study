#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, num, cnt = 0;

	cin >> n >> m;

	deque<int> dq;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		int idx;

		for (int j = 0; j < dq.size(); j++) {
			if (num == dq[j]) {
				idx = j;
				break;
			}
		}

		int size = dq.size();

		if (idx <= size / 2) {
			cnt += idx;
			rotate(dq.begin(), dq.begin() + idx, dq.end());
			dq.pop_front();
		}
		else {
			cnt += (dq.size() - idx);
			rotate(dq.begin(), dq.end() - (dq.size() - idx - 1), dq.end());
			dq.pop_back();
		}
	}
	cout << cnt;
}