#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

typedef struct road {
	int from, to, t;
}road;

bool bellman(int node,vector<road> &v) {
	vector<int> dis(node, 0);

	for (int i = 1; i < node; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].from;
			int to = v[j].to;
			int time = v[j].t;

			dis[to] = min(dis[to], dis[from] + time);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int from = v[i].from;
		int to = v[i].to;
		int time = v[i].t;

		if (dis[from] == INF)continue;
		if (dis[to] > dis[from] + time)return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;

	while (tc--) {
		int n, m, w, s, e, t;
		cin >> n >> m >> w;

		vector<road> edge;

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edge.push_back({ s - 1, e - 1,t });
			edge.push_back({ e - 1, s - 1,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edge.push_back({ s - 1, e - 1,-t });
		}
		
		if (bellman(n, edge))cout << "YES\n";
		else cout << "NO\n";
	}
}