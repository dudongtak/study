#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

vector<string> answer;
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	string str;

	map<string, int> name;

	for (int i = 0; i < n; i++) {
		cin >> str;
		name[str]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		name[str]++;
	}

	for (auto it : name) {
		if (it.second == 2)answer.push_back(it.first);
	}

	sort(answer.begin(), answer.end());
	int s = answer.size();
	cout << s << "\n";
	for (int i = 0; i < s; i++) {
		cout << answer[i] << "\n";
	}
}