#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> arr(N);
	vector<int> answer(N);
	stack<int> s;

	for (int i = 0; i < N; i++)cin >> arr[i];

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) s.pop();
		if (s.empty())answer[i] = -1;
		else answer[i] = s.top();
		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)cout << answer[i] << " ";
}