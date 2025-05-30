#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;

	vector<pair<int, int>> p;
	vector<int> move;
	double slope;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		p.push_back({ x,y });
	}

	int res = p[0].first*p[1].second + p[1].first*p[2].second + p[2].first*p[0].second - p[0].second*p[1].first - p[1].second*p[2].first - p[2].second*p[0].first;

	if (res > 0)cout << 1;
	else if (res < 0)cout << -1;
	else cout << 0;
}