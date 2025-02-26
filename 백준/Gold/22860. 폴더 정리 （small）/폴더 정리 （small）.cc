#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int n, m, q;
unordered_map<string, vector<pair<int, string>>> g;//key 상위 폴더 vlaue 하위 파일 vector
unordered_map<string, int> visit;
int f_cnt = 0, t_cnt = 0;

void dfs(string str) {
	for (auto it : g[str]) {
		if (it.first == 0 ) {
			f_cnt++;
			if (visit[it.second]==0) {
				visit[it.second]++;
				t_cnt++;
			}
		}
		if (it.first == 1) {
			dfs(it.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		string p, f;
		int c;
		cin >> p >> f >> c;
		vector<pair<int, string>> v = g[p];
		v.push_back({ c,f });
		g[p] = v;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		string str = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '/') {
				str = "";
			}
			else {
				str += s[j];
			}
		}

		dfs(str);
		cout << t_cnt << " " << f_cnt << "\n";
		f_cnt = 0; t_cnt = 0; visit.clear();
	}
}