#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	vector<int> s(N);
	vector<int> center;
	for (int i = 0; i < N; i++)cin >> s[i];
	sort(s.begin(), s.end());

	for (int i = 0; i < N - 1; i++)center.push_back(s[i + 1] - s[i]);
	sort(center.begin(), center.end(), greater<>());

	for (int i = K - 1; i < N - 1; i++)answer += center[i];

	cout << answer;
}