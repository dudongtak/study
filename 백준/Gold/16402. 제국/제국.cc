#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;


int N, M, w;
map<string, string> parent;
string str;
set<string> answer;

string Find(string s) {
	if (parent[s] == s)return s;
	return parent[s] = Find(parent[s]);
}

void Union(string s1, string s2) {
	string a = Find(s1);
	string b = Find(s2);

	if (a == b) {
		for (auto c : parent)if (c.second == a)parent[c.first] = s2;
	}
	else {
		parent[a] = b;
		for (auto c : parent)if (c.second == a)parent[c.first] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, str);
		parent[str] = str;
	}

	for (int i = 0; i < M; i++) {
		getline(cin, str);

		string tmp;
		vector<string> emp;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] != ',')tmp.push_back(str[j]);
			else {
				emp.push_back(tmp);
				tmp.clear();
			}
		}
		w = stoi(tmp);

		if (w == 1)Union(emp[1], emp[0]);
		else Union(emp[0], emp[1]);
	}

	for (auto c : parent)answer.insert(c.second);

	cout << answer.size() << "\n";
	for (auto c : answer)cout << c << "\n";
}