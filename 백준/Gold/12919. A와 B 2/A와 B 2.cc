#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str1, str2;
int answer = 0;

void dfs(string s) {
	if (s == str1) {
		answer = 1;
	}
	if (str1.size() >= s.size())return;
	if (s[s.size() - 1] == 'A') {
		string tmp = s;
		tmp.erase(tmp.size() - 1);
		dfs(tmp);
	}
	if (s[0] == 'B') {
		string tmp = s;
		tmp.erase(tmp.begin());
		reverse(tmp.begin(), tmp.end());
		dfs(tmp);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str1 >> str2;

	dfs(str2);

	cout << answer;
}