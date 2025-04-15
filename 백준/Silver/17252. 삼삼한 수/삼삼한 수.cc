#include<iostream>
#include<vector>
using namespace std;

long long num;
vector<long long> t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;
	if (num == 0) {
		cout << "NO";
		return 0;
	}
	long long n = 1;
	while (n <= num) {
		t.push_back(n);
		n *= 3;
	}
	int idx = t.size() - 1;
	while (idx >= 0 && num != 0) {
		if (num >= t[idx]) { num -= t[idx]; idx--; }
		else idx--;
	}

	if (num == 0)cout << "YES";
	else cout << "NO";
}