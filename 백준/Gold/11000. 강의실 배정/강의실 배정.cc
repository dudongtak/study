#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, s, t;
typedef pair<int, int> pii;
bool cmp(pii &a, pii &b) {
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}
vector<pii> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		v.push_back({ s,t });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)pq.pop();
	}

	cout << pq.size();
}