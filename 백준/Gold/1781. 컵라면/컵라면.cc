#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int d, r;
		cin >> d >> r;
		v.push_back({ d,r });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cnt += v[i].second;
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			cnt -= pq.top();
			pq.pop();
		}
	}
	
	cout << cnt;
}