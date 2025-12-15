#include<iostream>
using namespace std;

int n;

void make_star(int i,int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (num / 3 == 0)cout << '*';
		else make_star(i, j, num / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			make_star(i, j, n);
		}
		cout << '\n';
	}
}