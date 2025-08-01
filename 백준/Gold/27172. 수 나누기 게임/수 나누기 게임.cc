#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> nums;
vector<int> score(1000001, 0);
vector<bool> visit(1000001, false);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		visit[nums[i]] = true;
	}

	for (int i = 0; i < N; i++) {
		int num = nums[i];
		for (int j = num * 2; j <= 1000000; j += num) {
			if (visit[j]) {
				score[num]++;
				score[j]--;
			}
		}
	}

	for (int i = 0; i < N; i++)cout << score[nums[i]] << " ";
}