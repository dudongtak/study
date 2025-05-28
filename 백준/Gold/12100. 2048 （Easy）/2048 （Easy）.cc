#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int Max = 0;

void back_tracking(int cnt, vector<vector<int>> &b) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++)Max = max(Max, *max_element(b[i].begin(), b[i].end()));
		return;
	}

	vector<vector<int>> tmp = b;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			for (int j = 0; j < N - 1; j++) {
				for (int k = 0; k < N; k++) {
					int idx = j;
					while (idx < N - 1 && b[idx + 1][k] == 0)idx++;

					if (idx == N - 1)continue;

					if (b[j][k] == b[idx + 1][k]) {
						b[j][k] += b[idx + 1][k];
						b[idx + 1][k] = 0;
					}
				}
			}
			for (int j = 0; j < N; j++) {
				for (int k = 1; k < N; k++) {
					int idx = k;
					int ntmp = b[k][j];
					if (ntmp == 0)continue;
					while (idx > 0 && b[idx - 1][j] == 0)idx--;

					if (idx != k) {
						b[idx][j] = ntmp;
						b[k][j] = 0;
					}
				}
			}
		}
		if (i == 1) {
			for (int j = N - 1; j > 0; j--) {
				for (int k = 0; k < N; k++) {
					int idx = j;
					while (idx > 0 && b[idx - 1][k] == 0)idx--;

					if (idx == 0)continue;

					if (b[j][k] == b[idx - 1][k]) {
						b[j][k] += b[idx - 1][k];
						b[idx - 1][k] = 0;
					}
				}
			}
			for (int j = 0; j < N; j++) {
				for (int k = N - 2; k >= 0; k--) {
					int idx = k;
					int ntmp = b[k][j];
					if (ntmp == 0)continue;
					while (idx < N - 1 && b[idx + 1][j] == 0) idx++;
					if (idx != k) {
						b[idx][j] = ntmp;
						b[k][j] = 0;
					}
				}
			}
		}
		if (i == 2) {
			for (int j = N - 1; j > 0; j--) {
				for (int k = 0; k < N; k++) {
					int idx = j;
					while (idx > 0 && b[k][idx - 1] == 0)idx--;

					if (idx == 0)continue;

					if (b[k][j] == b[k][idx - 1]) {
						b[k][j] += b[k][idx - 1];
						b[k][idx - 1] = 0;
					}
				}
			}
			for (int j = 0; j < N; j++) {
				for (int k = N - 2; k >= 0; k--) {
					int idx = k;
					int ntmp = b[j][k];
					if (ntmp == 0)continue;
					while (idx < N - 1 && b[j][idx + 1] == 0) idx++;
					if (idx != k) {
						b[j][idx] = ntmp;
						b[j][k] = 0;
					}
				}
			}
		}
		if (i == 3) {
			for (int j = 0; j < N - 1; j++) {
				for (int k = 0; k < N; k++) {
					int idx = j;
					while (idx < N - 1 && b[k][idx + 1] == 0)idx++;

					if (idx == N - 1)continue;

					if (b[k][j] == b[k][idx + 1]) {
						b[k][j] += b[k][idx + 1];
						b[k][idx + 1] = 0;
					}
				}
			}
			for (int j = 0; j < N; j++) {
				for (int k = 1; k < N; k++) {
					int idx = k;
					int ntmp = b[j][k];
					if (ntmp == 0)continue;
					while (idx > 0 && b[j][idx - 1] == 0)idx--;

					if (idx != k) {
						b[j][idx] = ntmp;
						b[j][k] = 0;
					}
				}
			}
		}

		back_tracking(cnt + 1, b);
		b = tmp;
	}

	b = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> board[i][j];

	back_tracking(0, board);

	cout << Max;
}