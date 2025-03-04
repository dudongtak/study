#include<iostream>
#include<string>
#include<map>
using namespace std;

string str, password;
int mod = 900528;
map<char, int> m;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> password;

	int cnt = 0;
	int s_l = str.length();
	int p_l = password.length();

	for (int i = 0; i < s_l; i++) {
		m[str[i]] = i + 1;
	}

	for (int i = 0; i < p_l; i++) {
		cnt = (cnt*s_l + m[password[i]]) % mod;
	}

	cout << cnt;
}