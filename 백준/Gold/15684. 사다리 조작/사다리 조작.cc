#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, H, a, b;
vector<vector<int>> line(32, vector<int>(11, 0));
int answer = -1;
typedef pair<int, int> pii;
vector<pii> able;

bool check() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (line[j][cur] == 1) {
				cur++;
			}
			else if (line[j][cur - 1] == 1) {
				cur--;
			}
		}
		if (cur != i)return false;
	}
	return true;
}

void dfs(int idx, int l, int cnt) {
	if (answer != -1)return;
	if (l == cnt) {
		if (check())answer = cnt;
		return;
	}
	for (int i = idx; i < able.size(); i++) {
		int a = able[i].first;
		int b = able[i].second;

		if (line[a][b] == 0 && line[a][b - 1] == 0 && line[a][b + 1] == 0) {
			line[a][b] = 1;
			dfs(i + 1, l + 1, cnt);
			line[a][b] = 0;
			if (answer != -1)return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		line[a][b] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (line[j][i] == 0)able.push_back({ j, i });
		}
	}

	for (int i = 0; i <= 3; i++) {
		dfs(0, 0, i);
		if (answer != -1)break;

	}
	cout << answer;
	return 0;
}