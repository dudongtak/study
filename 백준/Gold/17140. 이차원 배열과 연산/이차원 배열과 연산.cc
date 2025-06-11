#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>> arr;
int R, C, K, cnt = 0;
struct cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		if (a.first == b.first)return a.second > b.second;
		return a.first > b.first;
	}
};
vector<vector<int>> rotate_clockwise() {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> rotated(m, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotated[j][n - 1 - i] = arr[i][j];
	return rotated;
}

vector<vector<int>> rotate_counterclockwise() {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> rotated(m, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotated[m - 1 - j][i] = arr[i][j];
	return rotated;
}

void op() {
	int length = 0;
	vector<vector<int>> arrtmp;
	for (int i = 0; i < arr.size(); i++) {
		vector<int> nums(101, 0);

		for (int j = 0; j < arr[i].size(); j++) {
			nums[arr[i][j]]++;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int j = 1; j <= 100; j++)if (nums[j] != 0)pq.push({ nums[j],j });

		vector<int> tmp;
		while (!pq.empty()) {
			tmp.push_back(pq.top().second);
			tmp.push_back(pq.top().first);
			pq.pop();
			if (tmp.size() == 100)break;
		}

		length = max(length, (int)tmp.size());
		arrtmp.push_back(tmp);
	}

	for (int i = 0; i < arrtmp.size(); i++)if (arrtmp[i].size() < length) while (arrtmp[i].size() != length)arrtmp[i].push_back(0);

	arr = arrtmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < 3; i++) {
		vector<int> tmp;
		for (int j = 0; j < 3; j++) {
			int num;
			cin >> num;
			tmp.push_back(num);
		}
		arr.push_back(tmp);
	}
	while (cnt<=100) {
		if (arr.size() >= R && arr[0].size() >= C && arr[R - 1][C - 1] == K)break;

		if (arr[0].size() <= arr.size()) {
			op();
		}
		else {
			arr = rotate_counterclockwise();
			op();
			arr = rotate_clockwise();
		}
		cnt++;
	}
	if (cnt > 100)cout << -1;
	else cout << cnt;
}