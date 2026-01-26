#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n, l;
vector<int> coord;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> l;

	coord.resize(m);
	for (int i = 0; i < m; i++)cin >> coord[i];
	sort(coord.begin(), coord.end());

	int answer = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		if (y > l)continue;

		int low = x + y - l, high = x - y + l;

		int s = 0, e = m - 1;
		while (s <= e) {
			int mid = (s + e) / 2;

			if (low <= coord[mid] && coord[mid] <= high) {
				answer++;
				break;
			}
			else if (coord[mid] < low) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}
	cout << answer;
}