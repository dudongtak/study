#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> answer(N);
	stack<int> s;
	vector<int> cnts(1000001, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnts[arr[i]]++;
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && cnts[s.top()] <= cnts[arr[i]])s.pop();
		if (s.empty())answer[i] = -1;
		else answer[i] = s.top();
		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)cout << answer[i] << " ";
}