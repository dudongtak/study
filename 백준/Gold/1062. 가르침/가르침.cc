#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int N, K;
string str;
vector<bool> alpha(26);
vector<string> sv;
int Max = 0;

int canRead() {
	bool read;
	int cnt = 0;
	for (int i = 0; i < sv.size(); i++) {
		read = true;
		str = sv[i];
		for (int j = 0; j < str.size(); j++) {
			if (!alpha[str[j] - 'a']) {
				read = false;
				break;
			}
		}
		if (read)cnt++;
	}
	return cnt;
}

void dfs(int idx,int cnt) {
	if (cnt == K) {
		Max = max(Max, canRead());
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i])continue;
		alpha[i] = true;
		dfs(i, cnt + 1);
		alpha[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> str;
		sv.push_back(str);
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}

	alpha[0] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	K -= 5;
	dfs(0, 0);

	cout << Max;
}