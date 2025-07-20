#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Max = 15;
vector<int> col(15, -1);
int N;
int answer = 0;

bool check(int row) {
	for (int i = 0; i < row; i++) {
		if (col[row] == col[i] || row - i == abs(col[row] - col[i]))return false;
	}
	return true;
}

void dfs(int row) {
	if (row == N ) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		col[row] = i;

		if (check(row))dfs(row + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dfs(0);

	cout << answer;
}