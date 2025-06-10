#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int T, F;

unordered_map<string, string> f;
unordered_map<string, int> cnt;

string Find(string v) {
	if (f[v] == v)return v;
	return f[v] = Find(f[v]);
}

void Union(string a, string b) {
	string x = Find(a);
	string y = Find(b);

	if (x == y)return;

	f[y] = x;
	cnt[x] += cnt[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	while (T--) {
		cin >> F;

		f.clear();
		cnt.clear();

		for (int i = 0; i < F; i++) {
			string n1, n2;
			cin >> n1 >> n2;

			if (f.count(n1) == 0) {
				f.insert({ n1,n1 });
				cnt.insert({ n1,1 });
			}
			if (f.count(n2) == 0) {
				f.insert({ n2,n2 });
				cnt.insert({ n2,1 });
			}

			Union(n1, n2);
			cout << cnt[Find(n1)] << '\n';
		}
	}
}