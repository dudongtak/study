#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;

int t;
typedef pair<int, int> pii;

void dijkstra(int s, vector<int> &dis,vector<vector<pii>> &b) {
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({ 0,s });
	dis[s] = 0;

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (dis[cur.second] < cur.first) continue;

		for (auto p : b[cur.second]) {
			int next = p.first;
			int w = p.second + cur.first;
			if (w >= dis[next])continue;
			dis[next] = w;
			pq.push({ w,next });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		int n, m, ta;
		cin >> n >> m >> ta;
		int s, g, h;
		cin >> s >> g >> h;

		vector<vector<pii>> board(n);
		vector<int> target(ta);

		int dis_gh = INF;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			board[a - 1].push_back({ b - 1,c });
			board[b - 1].push_back({ a - 1,c });
			if ((a == g && b == h) || (a == h && b == g))dis_gh = min(dis_gh, c);
		}

		for (int i = 0; i < ta; i++)cin >> target[i];

		vector<int> dis_s(n, INF);
		vector<int> dis_g(n, INF);
		vector<int> dis_h(n, INF);
		dijkstra(s - 1, dis_s, board);
		dijkstra(g - 1, dis_g, board);
		dijkstra(h - 1, dis_h, board);

		sort(target.begin(), target.end());

		for (auto c : target) {
			if (dis_s[c - 1] == dis_s[g - 1] + dis_gh + dis_h[c - 1] || dis_s[c - 1] == dis_s[h - 1] + dis_gh + dis_g[c - 1])cout << c << " ";
		}
		cout << "\n";
	}
}