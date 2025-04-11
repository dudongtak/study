#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int N;
ll h, o, L;

bool cmp(const pll& a, const pll& b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<pll> ho;

	for (int i = 0; i < N; i++) {
		cin >> h >> o;
		if (o < h) {
			swap(h, o);
		}
		ho.push_back({ h,o });
	}

	sort(ho.begin(), ho.end(), cmp);

	cin >> L;

	vector<pll> p;

	for (int i = 0; i < N; i++) {
		if (ho[i].second - ho[i].first <= L)p.push_back({ ho[i].first,ho[i].second });
	}
	
	int max_cnt = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	for (int i = 0; i < p.size(); i++) {
		ll end = p[i].second, start = end - L;

		while (!pq.empty() && pq.top().first < start)pq.pop();

		if (p[i].first >= start) {
			pq.push({ p[i].first,p[i].second });
			int pq_size = pq.size();
			max_cnt = max(max_cnt, pq_size);
		}
	}


	cout << max_cnt;
}