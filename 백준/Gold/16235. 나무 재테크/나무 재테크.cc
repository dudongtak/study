#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { 1,-1,0,1,-1,0,-1,1 };
int N, M, K;
vector<vector<vector<int>>> trees(10,vector<vector<int>>(10));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	vector<vector<int>> food(N, vector<int>(N, 0));
	vector<vector<int>> board(N, vector<int>(N, 5));

	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> food[i][j];

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}

	while (K--) {
		//봄 && 여름
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (trees[i][j].size() == 0)continue;

				int die_tree = 0;
				vector<int> tmp;

				sort(trees[i][j].begin(), trees[i][j].end());

				for (int k = 0; k < trees[i][j].size(); k++) {
					int age = trees[i][j][k];

					if (board[i][j] >= age) {
						board[i][j] -= age;
						tmp.push_back(age + 1);
					}
					else {
						die_tree += age / 2;
					}
				}

				trees[i][j] = tmp;
				board[i][j] += die_tree;
			}
		}
		//가을
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (trees[i][j].size() == 0)continue;

				for (int k = 0; k < trees[i][j].size(); k++) {
					int age = trees[i][j][k];

					if (age % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int nx = i + dx[l];
							int ny = j + dy[l];

							if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
							trees[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//겨울
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)board[i][j] += food[i][j];
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res += trees[i][j].size();
		}
	}
	cout << res;
}