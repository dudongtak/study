#include<iostream>
#include<queue>
using namespace std;

int n, op;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op != 0) {
			if (op > 0) {
				pq.push({ op,1 });
			}
			else {
				pq.push({ -op,0 });
			}
		}
		else {
			if (!pq.empty()) {
				if (pq.top().second == 1) {
					cout << pq.top().first << "\n";
				}
				else {
					cout << -pq.top().first << "\n";
				}
				pq.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
	}
}