#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, k;
map<int, long long> m;
vector<int> sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;;
	sum.push_back(0);
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum.push_back(sum[i - 1] + num);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] == k)ans++;
		ans += m[sum[i] - k];
		m[sum[i]]++;
	}
	cout << ans;
}