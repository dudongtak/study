#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<long long> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < n; i++) {
		int s = 0, e = n - 1, sum, tmp = num[i];
		while (s < e) {
			if (s == i) {
				s++; continue;
			}
			if (e == i) {
				e--; continue;
			}
			sum = num[s] + num[e];

			if (sum == tmp) {
				cnt++;
				break;
			}
			else if (sum > tmp) {
				e--;
			}
			else {
				s++;
			}
		}
	}

	cout << cnt;
}