#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;

int n;
stack<int> s;
vector<int> v(100001);
vector<int> cnt(1000001, 0);
vector<int> near(1000001, 10000001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = n ; i > 0; i--) {
		if (s.empty())s.push(i);
		else {
			while (!s.empty()) {
				if (v[i] < v[s.top()]) {
					near[i] = s.top();
					cnt[i] = s.size();
					break;
				}
				else {
					s.pop();
				}
			}
			s.push(i);
		}
	}

	while (!s.empty())s.pop();

	for (int i = 1; i <= n; i++) {
		if (s.empty())s.push(i);
		else {
			while (!s.empty()) {
				if (v[i] < v[s.top()]) {
					if (abs(near[i] - i) >= abs(i - s.top())) {
						near[i] = s.top();
					}
					cnt[i] += s.size();
					break;
				}
				else {
					s.pop();
				}
			}
			s.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i];
		if (cnt[i] != 0) {
			cout << " " << near[i];
		}
		cout << "\n";
	}
}