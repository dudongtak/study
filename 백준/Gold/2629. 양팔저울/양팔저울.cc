#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s_num, b_num, num, Max = 0;
vector<int> sinkers;
bool bead[40001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s_num;
	for (int i = 0; i < s_num; i++) {
		cin >> num;
		sinkers.push_back(num);
		Max += num;
	}
	sort(sinkers.begin(), sinkers.end(),greater<>());
	
	bead[0] = true;
	for (int i = 0; i < s_num; i++) {
		for (int j = Max; j >= 0; j--)
			if (bead[j])bead[j + sinkers[i]] = true;
		for (int j = 0; j <= Max; j++)
			if (bead[j])bead[abs(j - sinkers[i])] = 1;
	}

	cin >> b_num;
	for (int i = 0; i < b_num; i++) {
		cin >> num;
		if (bead[num])cout << "Y ";
		else cout << "N ";
	}
}