#include<iostream>
#include<vector>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)cin >> arr[i];

	vector<int> tmp;

	for (int i = 0; i < N; i++) {
		if (tmp.size() == 0 || tmp[tmp.size() - 1] < arr[i])tmp.push_back(arr[i]);
		else {
			int l = 0, r = tmp.size() - 1;
			while (l < r) {
				int m = (l + r) / 2;
				if (tmp[m] >= arr[i])r = m;
				else l = m + 1;
			}
			tmp[l] = arr[i];
		}
	}
	cout << tmp.size();
}