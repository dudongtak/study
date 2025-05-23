#include<iostream>
#include<string>
using namespace std;

int N;
string str;

int is_palindrome(int s, int e, int ans) {
	while (s < e) {
		if (str[s] != str[e]) {
			if (ans == 0) {
				if (is_palindrome(s + 1, e, 1) == 0 || is_palindrome(s, e - 1, 1) == 0)return 1;
				return 2;
			}
			else return 2;
		}
		else {
			s++; e--;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> str;
		int s = 0, e = str.length() - 1;

		int answer = is_palindrome(s, e, 0);

		cout << answer << "\n";
	}
}