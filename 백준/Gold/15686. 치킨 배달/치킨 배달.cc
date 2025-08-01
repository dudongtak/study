#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> board(50, vector<int>(50, 0));
typedef pair<int, int> pii;
vector<pii> chicken;
vector<pii> house;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)chicken.push_back({ i,j });
			if (board[i][j] == 1)house.push_back({ i,j });
		}
	}

	vector<bool> tmp(chicken.size(), false);
	for (int i = 0; i < M; i++)tmp[i] = true;

	int answer = 1000000000;

	do {
		int res = 0;
		vector<vector<int>> dis(house.size(), vector<int>(M, 0));
		int c_idx = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i]) {
				for (int j = 0; j < house.size(); j++) {
					dis[j][c_idx] = abs(house[j].first - chicken[i].first) + abs(house[j].second - chicken[i].second);
				}
				c_idx++;
			}
		}

		for (int i = 0; i < house.size(); i++) {
			res += *min_element(dis[i].begin(), dis[i].end());
		}
		answer = min(answer, res);
	} while (prev_permutation(tmp.begin(),tmp.end()));

	cout << answer;
}