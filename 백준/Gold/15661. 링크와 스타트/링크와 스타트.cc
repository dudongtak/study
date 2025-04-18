#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int N, Min = 1000000;
vector<vector<int>> board(21, vector<int>(21, 0));
vector<vector<int>> team;

void make_diff(int idx) {
	int l = 0, s = 0;
	vector<bool> is_l(N + 1, false);

	for (int i = 0; i < team[idx].size(); i++)is_l[team[idx][i]] = true;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (is_l[i]&&is_l[j]) {
				l += board[i][j];
			}
			else if (!is_l[i]&&!is_l[j]) {
				s += board[i][j];
			}
		}
	}
	Min = min(Min, abs(l - s));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> loc(N, 0);

	for (int i = 1; i <= N / 2; i++) {
		loc[i - 1] = 1;

		do {
			vector<int> tmp;
			for (int i = 0; i < N; i++) {
				if (loc[i] == 1)tmp.push_back(i + 1);
			}
			team.push_back(tmp);
		} while (prev_permutation(loc.begin(), loc.end()));
	}
	
	for (int i = 0; i < team.size(); i++)make_diff(i);

	cout << Min;
}