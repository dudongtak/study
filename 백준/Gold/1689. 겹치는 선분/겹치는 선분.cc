#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, s, e;
typedef pair<int, int> pii;
vector<pii> v(2000001);

int Max = 0;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		
		v[i] = { s,1 };
		v[i + N] = { e,-1 };
	}
	
	sort(v.begin(), v.begin() + 2 * N);

	for (int i = 0; i < N * 2; i++) {
		cnt += v[i].second;
		Max = max(Max, cnt);
	}

	cout << Max;
}