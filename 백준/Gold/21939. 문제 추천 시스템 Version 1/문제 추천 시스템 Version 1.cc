#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;

int n, m, p, l;
string q;
typedef pair<int, int> pii;
map<int, int> solved;

struct cmp1 {
	bool operator()(pii a, pii b) {
		if (a.first == b.first)return a.second < b.second;
		return a.first < b.first;
	}
};
struct cmp2 {
	bool operator()(pii a, pii b) {
		if (a.first == b.first)return a.second > b.second;
		return a.first > b.first;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pii, vector<pii>, cmp1> Max;
	priority_queue<pii, vector<pii>, cmp2> Min;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		Max.push({ l,p });
		Min.push({ l,p });
		solved[p] = l;
	}

	cin >> m;
	while (m--) {
		cin >> q;
		if (q == "add") {
			cin >> p >> l;
			Max.push({ l,p });
			Min.push({ l,p });
			solved[p] = l;
		}
		else {
			if (q == "solved") {
				cin >> p;
				solved.erase(p);
			}
			else {
				int op;
				cin >> op;
				if (op == 1) {
					while (true) {
						p = Max.top().second;
						l = Max.top().first;

						if (solved.count(p) && solved[p] == l)break;
						Max.pop();
					}
					cout << p << "\n";
				}
				else {
					while (true) {
						p = Min.top().second;
						l = Min.top().first;

						if (solved.count(p) && solved[p] == l)break;
						Min.pop();
					}
					cout << p << "\n";
				}
			}
		}
	}
}