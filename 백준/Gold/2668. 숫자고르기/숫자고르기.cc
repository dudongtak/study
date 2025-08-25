#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N;
vector<int> arr(101);
vector<bool> visit(101, false);
set<int> answer;
bool isRight;

void dfs(int s, int num) {
	if (visit[num]) {
		if (s == num) {
			isRight = true;
			answer.insert(num);
		}
		return;
	}

	visit[num] = true;
	dfs(s, arr[num]);
	if (isRight) {
		answer.insert(num);
		answer.insert(arr[num]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		dfs(i, arr[i]);
		visit = vector<bool>(101, false);
		isRight = false;
	}

	cout << answer.size() << "\n";
	for (auto n : answer)cout << n << "\n";
}