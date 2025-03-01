#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<>> min_pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (!min_pq.empty() && !max_pq.empty()) {
			if (min_pq.size() == max_pq.size()) {
				if (min_pq.top() < num) {
					max_pq.push(min_pq.top());
					min_pq.pop();
					min_pq.push(num);
				}
				else {
					max_pq.push(num);
				}
			}
			else {
				if (max_pq.top() > num) {
					min_pq.push(max_pq.top());
					max_pq.pop();
					max_pq.push(num);
				}
				else {
					min_pq.push(num);
				}
			}
		}
		else {
			if (max_pq.empty()) {
				max_pq.push(num);
			}
			else {
				if (max_pq.top() > num) {
					min_pq.push(max_pq.top());
					max_pq.pop();
					max_pq.push(num);
				}
				else {
					min_pq.push(num);
				}
			}
		}
		cout << max_pq.top() << "\n";
	}
}