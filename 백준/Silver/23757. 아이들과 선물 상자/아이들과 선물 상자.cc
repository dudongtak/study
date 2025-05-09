#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	priority_queue<int> pq;
	vector<int> child(M);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < M; i++)cin >> child[i];

	for (int i = 0; i < M; i++) {
		int tmp = pq.top();
		pq.pop();
		if (tmp < child[i]) {
			cout << 0;
			return 0;
		}
		tmp -= child[i];
		if (tmp != 0)pq.push(tmp);
	}
	cout << 1;
}