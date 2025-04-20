#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, L, s, e, cnt = 0;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		pq.push({ s,e });
	}

	int loc = pq.top().first;

	while (!pq.empty()) {
		s = pq.top().first;
		e = pq.top().second;

		if (loc > s)s = loc;
		else loc = s;
		pq.pop();
		while (loc < e) {
			loc += L;
			cnt++;
		}
	}
	cout << cnt;
}