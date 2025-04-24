#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<long long> arr;
int Max = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	arr.resize(N);
	vector<int> dp(N, 1);

	for (int i = 0; i < N; i++)cin >> arr[i];
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] % arr[j] == 0)dp[i] = max(dp[i], dp[j] + 1);
		}
		Max = max(Max, dp[i]);
	}

	cout << N - Max;
}