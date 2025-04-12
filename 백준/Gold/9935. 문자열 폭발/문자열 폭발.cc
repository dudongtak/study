#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

string str, bomb_str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> bomb_str;
	
	stack<char> s;
	string answer;

	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);

		if (str[i] == bomb_str[bomb_str.size() - 1] && s.size() >= bomb_str.size()) {
			string tmp;

			for (int j = 0; j < bomb_str.size(); j++) {
				tmp.push_back(s.top());s.pop();
			}

			reverse(tmp.begin(), tmp.end());

			if (tmp != bomb_str) {
				for (int j = 0; j < tmp.size(); j++)s.push(tmp[j]);
			}
		}
	}

	while (!s.empty()) {
		answer.push_back(s.top()); s.pop();
	}

	reverse(answer.begin(), answer.end());

	if (answer.empty()) cout << "FRULA";
	else cout << answer;
}