#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int n, t, m, l, answer;
int inf = 10000001;
vector<vector<tuple<int, int, int>>> board(101);
vector<pair<int, int>> dis(101, { inf,inf });

void dfs(int cur) {
	if (cur == n) {
		answer = min(answer, dis[cur].second);
		return;
	}
	for (int i = 0; i < board[cur].size(); i++) {
		if (dis[get<0>(board[cur][i])].first <= dis[cur].first + get<1>(board[cur][i]) && dis[get<0>(board[cur][i])].second <= dis[cur].second + get<2>(board[cur][i]))continue;
		else if (dis[cur].first + get<1>(board[cur][i]) > t || dis[cur].second + get<2>(board[cur][i]) > m)continue;
		dis[get<0>(board[cur][i])].first = dis[cur].first + get<1>(board[cur][i]);
		dis[get<0>(board[cur][i])].second = dis[cur].second + get<2>(board[cur][i]);
		dfs(get<0>(board[cur][i]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t >> m >> l;

	int from, to, time, cost;
	for (int i = 0; i < l; i++) {
		cin >> from >> to >> time >> cost;
		board[from].push_back({ to,time,cost });
		board[to].push_back({ from,time,cost });
	}
	answer = inf;
	dis[1] = { 0,0 };
	dfs(1);
	if (answer > m)cout << -1;
	else cout << answer;
}