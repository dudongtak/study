#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

int N, answer = 0;
vector<string> strs;
map<char, int> w;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	strs.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> strs[i];
		int l = strs[i].size();
		for (int j = 0; j < l; j++) {
			w[strs[i][j]] += pow(10, l - j - 1);
		}
	}

	vector<pair<char, int>> sorted(w.begin(), w.end());
	sort(sorted.begin(), sorted.end(),cmp);

	map<char, int> alpha;
	int num = 9;
	
	for (int i = 0; i < sorted.size(); i++)alpha[sorted[i].first] = num--;

	for (int i = 0; i < N;i++) {
		string cur = strs[i];
		int v = 0;
		for (int j = 0; j < cur.size(); j++)v = v * 10 + alpha[cur[j]];
		answer += v;
	}

	cout << answer;
}