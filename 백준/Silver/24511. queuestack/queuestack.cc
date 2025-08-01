#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, op, M, num;
vector<int> qs;
vector<int> data_struct;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	data_struct.resize(N);
	qs.resize(N);

	for (int i = 0; i < N; i++)cin >> data_struct[i];
	for (int i = 0; i < N; i++) cin >> qs[i];

	for (int i = N - 1; i >= 0; i--)if (data_struct[i] == 0)q.push(qs[i]);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		q.push(num);
		cout << q.front() << " ";
		q.pop();
	}
}