#include<iostream>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> map(10000);
vector<int> visit(10000, 0);
int a = 0;

void dfs(int start,int sum) {
	visit[start] = 1;

	for (int i = 0; i < map[start].size(); i++) {
		if (visit[map[start][i].first] == 0) {
			if (a < sum + map[start][i].second) {
				a = sum + map[start][i].second;
			}
			dfs(map[start][i].first, sum + map[start][i].second);
		}
	}
	visit[start] = 0;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int s, e, l;
		scanf("%d %d %d", &s, &e, &l);
		map[s - 1].emplace_back(e - 1, l);
		map[e - 1].emplace_back(s - 1, l);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}

	printf("%d", a);
}