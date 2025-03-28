#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long ll;
int n;
vector<ll> liquid(100000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}

	int s = 0, e = n - 1;
	ll al, ac;
	ll Min = pow(10, 10);

	while (s < e) {
		ll l = liquid[e] + liquid[s];

		if (abs(l) < abs(Min)) {
			Min = l;
			al = liquid[s];
			ac = liquid[e];
		}
		if (abs(l) == abs(Min) && l < 0) {
			al = liquid[s];
			ac = liquid[e];
		}
		if (abs(liquid[s]) > abs(liquid[e]))s++;
		else e--;
	}
	cout << al << " " << ac;
}