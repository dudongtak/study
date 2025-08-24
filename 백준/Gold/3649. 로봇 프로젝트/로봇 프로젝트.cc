#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int x, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin>>x>>n) {
		x *= 10000000;

		vector<int> lego(n);

		for (int i = 0; i < n; i++) {
			cin >> lego[i];
		}

		sort(lego.begin(), lego.begin() + n);

		int s = 0, e = n - 1, m;

		int max = -1, max_s, max_e;

		while (s < e) {
			int sum = lego[s] + lego[e];
			if (sum == x) {
				int diff = lego[e] - lego[s];
				if (diff>max) {
					max = diff;
					max_s = lego[s];
					max_e = lego[e];
				}
				s++;
				e--;
			}
			else if (sum < x) {
				s++;
			}
			else {
				e--;
			}

		}
		if (max != -1) {
			cout << "yes " << max_s << " " << max_e << "\n";
		}
		else cout << "danger\n";
		
	}
}