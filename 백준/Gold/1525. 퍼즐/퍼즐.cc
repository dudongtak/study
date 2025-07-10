#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int answer = -1;
string target = "123456780", start = "";
set<string> visit;
queue<pair<string, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		char num;
		cin >> num;
		start += num;
	}

	visit.insert(start);
	q.push({ start,0 });

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == target && (answer = -1 || answer > cnt))answer = cnt;

		int idx_z = cur.find('0');
		int x = idx_z / 3, y = idx_z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3)continue;
			string next = cur;
			swap(next[x * 3 + y], next[nx * 3 + ny]);

			if (visit.find(next) != visit.end())continue;
			visit.insert(next);
			q.push({ next,cnt + 1 });
		}
	}

	cout << answer;
}