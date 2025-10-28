#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> sc;

	for (int i = 0; i < n; i++) {
		int s, f;
		scanf("%d %d", &s, &f);
		sc.push_back(make_pair(f, s));
	}

	sort(sc.begin(), sc.end());

	int cnt = 1;
	int f = sc[0].first;

	for (int i = 1; i < n; i++) {
		if (sc[i].second >= f) {
			cnt++;
			f = sc[i].first;
		}
	}

	printf("%d", cnt);
}