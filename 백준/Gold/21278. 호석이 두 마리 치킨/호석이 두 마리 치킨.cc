#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> dis(n, vector<int>(n, 1e9));

	for (int i = 0; i < n; i++)dis[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dis[a - 1][b - 1] = 1;
		dis[b - 1][a - 1] = 1;
	}

	for (int mid = 0; mid < n; mid++) {
		for (int s = 0; s < n; s++) {
			for (int e = 0; e < n; e++) {
				dis[s][e] = min(dis[s][e], dis[s][mid] + dis[mid][e]);
			}
		}
	}

	vector<bool> tmp(n, false);
	tmp[0] = true;
	tmp[1] = true;
	vector<int> ans(3, -1);
	ans[2] = 1e9;

	do {
		int Min = 0;
		vector<int> c;
		for (int i = 0; i < n; i++)if (tmp[i])c.push_back(i);
		for (int i = 0; i < n; i++) {
			if (i == c[0] || i == c[1])continue;
			Min += min(dis[c[0]][i], dis[c[1]][i]) * 2;
		}
		if (ans[2] > Min) {
			ans[0] = c[0];
			ans[1] = c[1];
			ans[2] = Min;
		}
	} while (prev_permutation(tmp.begin(), tmp.end()));
	cout << ans[0] + 1 << " " << ans[1] + 1 << " " << ans[2];
}