#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

unsigned long long N;
vector<int> dice(6);// A B C D E F
unsigned long long answer = 0;

bool check(int idx1,int idx2) {
	if (idx1 == 0 && idx2 == 5)return true;
	if (idx1 == 5 && idx2 == 0)return true;
	if (idx1 == 1 && idx2 == 4)return true;
	if (idx1 == 4 && idx2 == 1)return true;
	if (idx1 == 2 && idx2 == 3)return true;
	if (idx1 == 3 && idx2 == 2)return true;
	return false;
}

pair<int,int> find_min(int idx) {
	vector<int> tmp = dice;
	if (5 - idx == 0 || 5 - idx == 5) { 
		tmp[5] = 51;
		tmp[0] = 51;
	}
	if (5 - idx == 1 || 5 - idx == 4) {
		tmp[4] = 51;
		tmp[1] = 51;
	}
	if (5 - idx == 2 || 5 - idx == 3) {
		tmp[3] = 51;
		tmp[2] = 51;
	}

	int Min = *min_element(tmp.begin(), tmp.end());
	int min_idx = find(tmp.begin(), tmp.end(), Min) - tmp.begin();
	tmp[min_idx] = 51;

	int sMin = *min_element(tmp.begin(), tmp.end());
	int s_min_idx = find(tmp.begin(), tmp.end(), sMin) - tmp.begin();
	if (check(min_idx, s_min_idx)) {
		tmp[s_min_idx] = 51;
		sMin = *min_element(tmp.begin(), tmp.end());
	}

	return { Min,sMin };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < 6; i++)cin >> dice[i];

	if (N == 1) {
		int Max = *max_element(dice.begin(), dice.end());
		int max_idx = find(dice.begin(), dice.end(), Max) - dice.begin();
		if (max_idx == 0) {
			cout << dice[5] + dice[1] + dice[2] + dice[3] + dice[4];
		}
		if (max_idx == 1) {
			cout << dice[0] + dice[4] + dice[2] + dice[3] + dice[5];
		}
		if (max_idx == 2) {
			cout << dice[0] + dice[1] + dice[3] + dice[4] + dice[5];
		}
		if (max_idx == 3) {
			cout << dice[0] + dice[1] + dice[2] + dice[4] + dice[5];
		}
		if (max_idx == 4) {
			cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[5];
		}
		if (max_idx == 5) {
			cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		}
		return 0;
	}

	int Min = *min_element(dice.begin(), dice.end());
	int min_idx = find(dice.begin(), dice.end(), Min) - dice.begin();

	answer += N * N * Min;

	pair<int, int> min_pair = find_min(min_idx);

	answer += 4 * min_pair.second;
	answer += 4 * min_pair.first;
	answer += 4 * (N - 2)*min_pair.first;
	answer += 2 * (N - 1)*N*Min;
	answer += 2 * (N - 1)*(N - 2)*Min;
	answer += 4 * (N - 1)*min_pair.first;

	cout << answer;
}