#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> board;
vector<int> arr;
typedef struct info {
	int dis, x, y;
}info;

bool cmp(const info &a, const info &b) {
	return a.dis < b.dis;
}
vector<info> in;

int Find(int a) {
	if (a == arr[a])return a;
	return arr[a] = Find(arr[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B)return;
	if (A < B)arr[B] = A;
	else arr[A] = B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	board.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> board[i][j];
	for (int i = 0; i < N; i++)arr.push_back(i);

	for (int i = 0; i < N; i++)for (int j = i + 1; j < N; j++)in.push_back({ board[i][j],i,j });
	sort(in.begin(), in.end(), cmp);

	long long answer = 0;

	for (int i = 0; i < in.size(); i++) {
		if (Find(in[i].x) == Find(in[i].y))continue;
		answer += in[i].dis;
		Union(in[i].x, in[i].y);
	}

	cout << answer;
}