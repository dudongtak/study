#include<iostream>
#include<math.h>
using namespace std;

int INF = 100001;
int x, y, sx, sy, sdiff, diff;

void make_small() {
	sdiff = abs(sx - sy);
	if (sx == sy)sx = sy = 1;
	else {
		while (sdiff % 2 == 0)sdiff /= 2;
		if (sx < sy) {
			sx = 1;
			sy = 1 + sdiff;
		}
		else {
			sy = 1;
			sx = 1 + sdiff;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> sx >> sy;
	make_small();

	for (int i = 0; i < 5; i++) {
		cin >> x >> y;
		if ((sx <= sy) != (x <= y))cout << "N\n";
		else {
			diff = abs(x - y);
			if (diff*sdiff == 0) {
				if (diff == sdiff)cout << "Y\n";
				else cout << "N\n";
			}
			else {
				if (diff%sdiff == 0)cout << "Y\n";
				else cout << "N\n";
			}
		}
	}
}