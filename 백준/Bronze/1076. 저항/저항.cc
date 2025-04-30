#include<iostream>
#include<map>
#include<string>
#include<math.h>
using namespace std;

typedef pair<int, int> pii;
map<string, pair<int, int>> m;
string str[] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pii p;
	for (int i = 0; i < 10; i++) {
		int n = pow(10, i);
		p = { i,n };
		m[str[i]] = p;
	}
	string ans = "";
	long long answer;
	for (int i = 0; i < 3; i++) {
		string tmp;
		cin >> tmp;
		if (i != 2)ans += to_string(m[tmp].first);
		else {
			answer = stoll(ans)*m[tmp].second;
		}
	}
	cout << answer;
}