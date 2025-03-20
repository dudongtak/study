#include<iostream>
#include<queue>
#include<vector>
#include<numeric>
using namespace std;

int n, d, w, answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		pq.push({ w,d });
	}

	vector<int> score(1001, 0);

	while (!pq.empty()) {
		int date = pq.top().second;

		for (int i = date; i > 0; i--) {
			if (score[i] == 0) {
				score[i] = pq.top().first;
				break;
			}
		}
		pq.pop();
	}

	cout << accumulate(score.begin(), score.end(), 0);
}