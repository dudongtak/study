#include<iostream>
#include<vector>
using namespace std;

vector<int> arr(10001);

void post(int s, int e) {
	if (s >= e)return;

	int root = arr[s];
	int delim = s + 1;

	while (delim < e) {
		if (root < arr[delim])break;
		delim++;
	}

	post(s + 1, delim);
	post(delim, e);
	cout << root << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx = 0, num;

	while (cin >> num)arr[idx++] = num;
	post(0, idx);
}