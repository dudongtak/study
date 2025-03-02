#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<long long, long long>> moods;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	long double area = 0;

	long long x, y;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		moods.push_back({ x,y });
	}

	for (int i = 1; i < n - 1; i++) {
		long double ld1 = (moods[i].first - moods[0].first);
		long double ld2 = (moods[i + 1].second - moods[0].second);
		long double ld3 = (moods[i].second - moods[0].second);
		long double ld4 = (moods[i + 1].first - moods[0].first);
		area += ld1 * ld2 - ld3 * ld4;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(area) / 2;
}