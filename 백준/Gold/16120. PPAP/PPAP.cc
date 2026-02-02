#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	stack<char> s;

	for (int i = 0; i < str.size(); i++) {

		s.push(str[i]);

		if (s.size() >= 4 && str[i] == 'P') {

			string ppap = "";

			for (int j = 0; j < 4; j++) {
				ppap.push_back(s.top());
				s.pop();
			}

			if (ppap == "PAPP") ppap = "P";

			for (int j = ppap.size() - 1; j >= 0; j--)s.push(ppap[j]);
		}
	}

	if (s.size() == 1 && s.top() == 'P')cout << "PPAP";
	else cout << "NP";
}