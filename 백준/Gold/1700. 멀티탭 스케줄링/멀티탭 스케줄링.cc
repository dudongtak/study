#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (N >= K) {
		cout << 0;
		return 0;
	}

	vector<int> tool(K);
	vector<int> tap(N,0);
	for (int i = 0; i < K; i++)cin >> tool[i];

	int tap_idx = 0, tool_idx = 0;

	while (tap_idx < N) {
		if (find(tap.begin(), tap.end(), tool[tool_idx]) == tap.end()) {
			tap[tap_idx] = tool[tool_idx];
			tap_idx++;
		}
		tool_idx++;
	}

	int answer = 0;

	for (int i = N; i < K; i++) {
		int cur = tool[i];

		if (find(tap.begin(), tap.end(), cur) == tap.end()) {
			pair<int, int> next = { 0,0 };

			for (int j = 0; j < N; j++) {
				pair<int, int> cur_tap;
				int pos = find(tool.begin() + i, tool.begin() + K, tap[j]) - tool.begin();

				if (pos == K)cur_tap = { 101,j };
				else cur_tap = { pos,j };

				if (cur_tap.first > next.first)next = cur_tap;
			}

			tap[next.second] = cur;
			answer++;
		}
	}
	cout << answer;
}