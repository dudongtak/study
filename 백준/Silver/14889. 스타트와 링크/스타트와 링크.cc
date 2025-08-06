#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<vector<int>> s(20, vector<int>(20, 0));


int status_differ(vector<bool> &p,int n) {
	int s_status = 0, l_status = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i]) {
				if (p[j]) {
					s_status += s[i][j];
				}
			}
			else {
				if (!p[j]) {
					l_status += s[i][j];
				}
			}
		}
	}
	return abs(s_status - l_status);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	vector<bool> permu(n, true);
	for (int i = 0; i < n / 2; i++) {
		permu[i] = false;
	}

	int answer = 10000000;

	do {
		answer = min(answer, status_differ(permu, n));
	} while (next_permutation(permu.begin(), permu.end()));

	cout << answer;
}