#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> light;
vector<int> dp;
int Max = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	light.resize(N);

	for (int i = 0; i < N; i++)cin >> light[i];

	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (light[i] == light[i - 1]) {
			dp.push_back(cnt);
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	dp.push_back(cnt);

	if (dp.size() == 1)Max = dp[0];
	else if (dp.size() == 2)Max = dp[0] + dp[1];
	else for (int i = 0; i < dp.size() - 2; i++)Max = max(Max, dp[i] + dp[i + 1] + dp[i + 2]);

	cout << Max;
}