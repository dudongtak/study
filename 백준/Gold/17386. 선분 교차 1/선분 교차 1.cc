#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point {
	int x, y;
};

int ccw(Point a, Point b, Point c) {
	ll val = (ll)a.x*b.y + (ll)b.x*c.y + (ll)c.x*a.y - (ll)a.y*b.x - (ll)b.y*c.x - (ll)c.y*a.x;
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

bool overlap(Point a, Point b, Point c, Point d) {
	if (a.x > b.x) swap(a, b);
	if (c.x > d.x) swap(c, d);
	if (a.x == b.x && c.x == d.x) {
		if (a.y > b.y) swap(a, b);
		if (c.y > d.y) swap(c, d);
		return max(a.y, c.y) <= min(b.y, d.y);
	}
	return max(a.x, c.x) <= min(b.x, d.x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Point p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;

	int ab_c = ccw(p1, p2, p3);
	int ab_d = ccw(p1, p2, p4);
	int cd_a = ccw(p3, p4, p1);
	int cd_b = ccw(p3, p4, p2);

	int res1 = ab_c * ab_d;
	int res2 = cd_a * cd_b;

	if (res1 == 0 && res2 == 0) {
		if (overlap(p1, p2, p3, p4)) cout << 1;
		else cout << 0;
	}
	else {
		if (res1 <= 0 && res2 <= 0) cout << 1;
		else cout << 0;
	}
}
