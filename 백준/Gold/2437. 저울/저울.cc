#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> w;
int answer = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	w.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	sort(w.begin(), w.end());

	for (int i = 0; i < N; i++) {
		if (w[i] > answer) {
			break;
		}
		answer += w[i];
	}
	cout << answer;
}