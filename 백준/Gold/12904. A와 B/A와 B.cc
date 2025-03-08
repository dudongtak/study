#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t;

	while (true) {
		if (s.size() == t.size()) {
			if (s == t)cout << 1;
			else cout << 0;
			break;
		}
		
		char tmp = t.back();
		t.pop_back();
		if (tmp == 'B')reverse(t.begin(), t.end());
	}
}