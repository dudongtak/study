#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int INF = 1001;
vector<vector<int>> board(501, vector<int>(501, INF));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	for (int i = 1; i <= N; i++)board[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			if (board[i][j] != INF || board[j][i] != INF)cnt++;
		}
		if (cnt == N - 1)res++;
	}
	cout << res;
}