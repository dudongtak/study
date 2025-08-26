#include<iostream>
#include<stack>
using namespace std;

int N, h;
stack<int> s;
long long answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> h;
		if (s.size() == 0) { s.push(h); continue; }
		
		while (!s.empty() && s.top() <= h) s.pop();

		answer += s.size();
		s.push(h);
	}

	cout << answer;
}