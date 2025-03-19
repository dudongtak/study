#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int t, k;
string w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t > 0) {
		t--;
		cin >> w >> k;

		vector<vector<int>> ABCs(26);

		for (int i = 0; i < w.size(); i++) {
			ABCs[w[i] - 'a'].push_back(i);
		}
		int Max = 0, Min = 10001;

		for (int i = 0; i < 26; i++) {
			if (ABCs[i].size() < k)continue;
			for (int j = 0; j <= ABCs[i].size() - k; j++) {
				Min = min(Min, ABCs[i][j + k - 1] - ABCs[i][j] + 1);
				Max = max(Max, ABCs[i][j + k - 1] - ABCs[i][j] + 1);
			}
		}

		if (Max == 0 || Min == 10001) {
			cout << -1 << "\n";
		}
		else {
			cout << Min << " " << Max << "\n";
		}
	}
}