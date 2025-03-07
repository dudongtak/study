#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;


long long n, m;
long long a, b, c;
long long inf = 100000000000;
vector<tuple<long long, long long, long long>> edge;
vector<long long> dis(501, inf);

bool bellman_ford(long long s) {
	dis[s] = 0;
	
	for (long long i = 1; i <= n - 1; i++) {
		for (long long j = 0; j < edge.size(); j++) {
			long long cur = get<0>(edge[j]);
			long long next = get<1>(edge[j]);
			long long cost = get<2>(edge[j]);

			if (dis[cur] == inf)continue;
			if (dis[next] > dis[cur] + cost)dis[next] = dis[cur] + cost;
		}
	}

	for (long long i = 0; i < edge.size(); i++) {
		long long cur = get<0>(edge[i]);
		long long next = get<1>(edge[i]);
		long long cost = get<2>(edge[i]);

		if (dis[cur] == inf)continue;
		if (dis[next] > dis[cur] + cost) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (long long i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
	}

	if (bellman_ford(1)) {
		for (long long i = 2; i <= n; i++) {
			if (dis[i] == inf) {
				cout << -1 << "\n";
				continue;
			}
			cout << dis[i] << "\n";
		}
	}
	else {
		cout << -1;
	}
}