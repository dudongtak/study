#include<iostream>
#include<string>
using namespace std;

int l;
string answer;
bool check = false;

void backTracking(string str, int depth) {
	if (check)return;
	int s = str.size();
	for (int i = 1; i <= s / 2; i++)if (str.substr(s - i, i) == str.substr(s - 2 * i, i))return;
	if (l == depth) {
		answer = str;
		check = true;
	}
	for (int i = 0; i < l; i++) {
		backTracking(str + '1', depth + 1);
		backTracking(str + '2', depth + 1);
		backTracking(str + '3', depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l;
	backTracking("", 0);

	cout << answer;
}