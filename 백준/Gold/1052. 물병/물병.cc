#include<iostream>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int cnt = 0;
	do {
		int count = 0;
		int  v = n;
		while (v > 0) {
			if ((v & 1) == 1)count++;
			v = v >> 1;
		}
		if (count <= k) {
			cout << cnt;
			return 0;
		}
		n++;
	} while (++cnt);
}