#include<iostream>
#include<vector>
#include<string>
using namespace std;

string str;
int q, l, r;
char a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> q;
	vector<vector<int>> alphabet(26, vector<int>(str.size() + 1, 0));

	for (int i = 1; i <= str.size(); i++) {
		for (int j = 0; j < 26; j++)alphabet[j][i] = alphabet[j][i - 1];
		alphabet[str[i - 1] - 'a'][i] += 1;
	}

	while (q--) {
		cin >> a >> l >> r;
		cout << alphabet[a - 'a'][r + 1] - alphabet[a - 'a'][l] << "\n";
	}
}