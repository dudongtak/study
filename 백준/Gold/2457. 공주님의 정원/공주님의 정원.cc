#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, sm, sd, em, ed;
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
vector<int> base(13, 0);
vector<pair<int,int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= 12; i++)base[i] = month[i - 1] + base[i - 1];

	for (int i = 0; i < N; i++) {
		cin >> sm >> sd >> em >> ed;
		v.push_back({ base[sm] + sd,base[em] + ed});
	}

	sort(v.begin(), v.end());

	int s = base[3] + 1, e = base[12];
	
	if (s < v[0].first) {
		cout << 0;
		return 0;
	}
	int idx = 0, cnt = 0;
	while (s <= e) {
		int new_e = 0;
		for (; idx < N; idx++) {
			if (v[idx].first >= v[idx].second)continue;
			if (s >= v[idx].first) {
				if (new_e < v[idx].second)new_e = v[idx].second;
			}
			else break;
		}
		if (new_e == 0)break;
		else {
			s = new_e;
			cnt++;
		}
	}
	if (s > e)cout << cnt;
	else cout << 0;
}