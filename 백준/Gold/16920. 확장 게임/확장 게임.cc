#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M, P;
vector<int> S;
vector<int> cnt;
vector<vector<char>> board;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> P;
	S.resize(P);
	cnt.assign(P, 0);
	board.assign(N, vector<char>(M));

	vector<queue<pair<int, int>>> Q(P);

	for (int i = 0; i < P; ++i) cin >> S[i];

	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		for (int j = 0; j < M; ++j) {
			board[i][j] = str[j];
			if ('1' <= str[j] && str[j] <= '9') {
				int idx = str[j] - '1';
				Q[idx].push({ i, j });
				cnt[idx]++;
			}
		}
	}

	bool updated = true;
	while (updated) {
		updated = false;
		for (int pid = 0; pid < P; ++pid) {
			queue<pair<int, int>> curQ, nextQ;
			curQ = Q[pid];
			Q[pid] = queue<pair<int, int>>();

			for (int step = 0; step < S[pid] && !curQ.empty(); ++step) {
				int qSize = curQ.size();
				for (int t = 0; t < qSize; ++t) {
					int x = curQ.front().first;
					int y = curQ.front().second;
					curQ.pop();

					for (int d = 0; d < 4; ++d) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] != '.') continue;
						board[nx][ny] = '1' + pid;
						nextQ.push({ nx, ny });
						cnt[pid]++;
						updated = true;
					}
				}
				curQ = nextQ;
				nextQ = queue<pair<int, int>>();
			}
			Q[pid] = curQ;
		}
	}

	for (int i = 0; i < P; ++i) cout << cnt[i] << " ";
	cout << "\n";
}