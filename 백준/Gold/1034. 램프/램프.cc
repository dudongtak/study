#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n, m, k, Max = 0;
vector<string> lamp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	lamp.resize(n);
	for (int i = 0; i < n; i++) cin >> lamp[i];

	cin >> k;

	for (int i = 0; i < n; i++) {
		int zeroCnt = 0;
		for (char c : lamp[i]) if (c == '0')zeroCnt++;

		if (k < zeroCnt)continue;
		if ((k - zeroCnt) % 2 == 1)continue;

		int cnt = 0;
		for (int j = 0; j < n; j++)if (lamp[j] == lamp[i])cnt++;
		Max = max(Max, cnt);
	}

	cout << Max;
}