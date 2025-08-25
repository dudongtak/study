#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> student;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	student.resize(N);
	for (int i = 0; i < N; i++)cin >> student[i];

	sort(student.begin(), student.begin() + N);
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			long long sum = student[i] + student[j];

			int s_idx = lower_bound(student.begin() + 1 + j, student.end(), -sum) - student.begin();
			int e_idx = upper_bound(student.begin() + 1 + j, student.end(), -sum) - student.begin();

			cnt += e_idx - s_idx;
		}
	}

	cout << cnt;
}