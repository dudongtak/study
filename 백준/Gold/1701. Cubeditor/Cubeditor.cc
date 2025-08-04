#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int kmp(string pa) {
	vector<int> table(5001, 0);
	int res = 0, j = 0;

	for (int i = 1; i < pa.size(); i++) {
		while (j > 0 && pa[i] != pa[j])j = table[j - 1];
		if (pa[j] == pa[i])table[i] = ++j;
		res = max(res, table[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int answer = 0;
	for (int i = 0; i < str.size(); i++) {
		answer = max(answer, kmp(str.substr(i)));
	}
	cout << answer;
}