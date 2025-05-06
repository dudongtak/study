#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int N, K;
int cnt = 0;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> str;

	stack<char> s;

	for (int i = 0; i < N; i++) {
		while (!s.empty() && cnt<K&&str[i]>s.top()) {
			cnt++;
			s.pop();
		}
		s.push(str[i]);
	}
	while (cnt < K) {
		cnt++;
		s.pop();
	}

	string answer;

	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
}