#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;

	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	vector<int> tmp = arr;
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());

	cin >> s;

	int idx = 0;

	while (idx < n && s > 0 && arr != tmp) {
		int end = min(idx + s + 1, n);
		int maxIdx = max_element(arr.begin() + idx, arr.begin() + end) - arr.begin();
		
		int temp = arr[maxIdx];
		for (int i = maxIdx; i > idx; i--)arr[i] = arr[i - 1];
		arr[idx] = temp;
		s -= (maxIdx - idx);
		idx++;
	}

	for (auto i : arr)cout << i << " ";
}