#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int n, k;
string name;
vector<int> student;	
map<int, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> name;
		student.push_back(name.size());
	}

	map<int, int> m;

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += m[student[i]];
		m[student[i]]++;
		if (i >= k)m[student[i-k]]--;
	}
	cout << cnt;
}