#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> crain;
vector<int> box;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	crain.resize(N);
	for (int i = 0; i < N; i++)cin >> crain[i];

	cin >> M;
	box.resize(M);
	for (int i = 0; i < M; i++)cin >> box[i];

	sort(crain.rbegin(), crain.rend());
	sort(box.rbegin(), box.rend());

	if (box[0] > crain[0]) {
		cout << -1;
		return 0;
	}
	
	int time = 0, move = 0;
	vector<bool> moved(M, false);

	while (move < M) {
		int box_idx = 0;
		for (int i = 0; i < N; i++) {
			while (box_idx < M) {
				if (!moved[box_idx] && crain[i] >= box[box_idx]) {
					moved[box_idx] = true;
					box_idx++;
					move++;
					break;
				}
				box_idx++;
			}
		}
		time++;
	}

	cout << time;
}