#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int N, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> parr;
	vector<int> marr;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n > 0)parr.push_back(n);
		else marr.push_back(n);
	}
	sort(parr.begin(), parr.end(),greater<>());
	sort(marr.begin(), marr.end());
	
	int answer = 0;
	for (int i = 0; i < parr.size(); i += 2) {
		if (i == parr.size() - 1) {
			answer += parr[i];
			break;
		}
		if (parr[i + 1] == 1)answer += parr[i] + parr[i + 1];
		else answer += parr[i] * parr[i + 1];
	}
	if (marr.size() % 2 == 1) {
		answer += marr[marr.size() - 1];
		marr.push_back(0);
	}
	for (int i = 0; i < marr.size(); i += 2) {
		answer += marr[i] * marr[i + 1];
	}
	cout << answer;
}