#include<iostream>
#include<set>
#include<vector>
using namespace std;

int Find(int v, vector<int> &vec) {
	if (v == vec[v])return v;
	return vec[v] = Find(vec[v], vec);
}

void Union(int a, int b, vector<int> &v) {
	int x = Find(a, v);
	int y = Find(b, v);
	v[x] = y;
}

bool isOver(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	int diffx = a.first.first - b.first.first;
	int diffy = a.first.second - b.first.second;

	long long  dis = diffx * diffx + diffy * diffy;
	long long r = (a.second + b.second)*(a.second + b.second);
	if (dis <= r)return true;
	return  false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> v(3000);
		vector<pair<pair<int, int>, int>> info;
		int X, Y, R;
		for (int i = 0; i < N; i++) {
			cin >> X >> Y >> R;
			v[i] = i;
			info.push_back({ {X,Y},R });
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (isOver(info[i], info[j]))Union(v[i], v[j], v);
			}
		}
		set<int> s;
		for (int i = 0; i < N; i++)s.insert(Find(i, v));
		cout << s.size() << "\n";
	}
}