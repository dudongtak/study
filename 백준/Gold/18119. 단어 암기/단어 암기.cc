#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, M;
vector<int> strs;
char o, x;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	strs.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (auto c : str) strs[i] |= 1 << (c - 'a');
	}
	int cur = (1 << 26) - 1;
	while (M--) {
		int cnt = 0;
		cin >> o >> x;
		if (o == '1') cur ^= 1 << (x - 'a');
		else cur |= 1 << (x - 'a');

		for (int i = 0; i < N; i++) {
			if (strs[i] == (strs[i] & cur)) cnt++;
		}
		cout << cnt << '\n';
	}
}