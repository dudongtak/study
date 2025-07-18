#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
typedef long long ll;
ll answer = 0;
vector<ll> ab;
vector<ll> cd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<vector<ll>> arr(4, vector<ll>(N));

	for (int i = 0; i < N; i++)for (int j = 0; j < 4; j++)cin >> arr[j][i];

	int idx = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		ab.push_back(arr[0][i] + arr[1][j]);
		cd.push_back(arr[2][i] + arr[3][j]);
		idx++;
	}
	
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	int ab_idx = 0, cd_idx = idx - 1;

	while (ab_idx < idx&&cd_idx >= 0) {
		if (ab[ab_idx] + cd[cd_idx] == 0) {
			ll ab_cnt = 0, cd_cnt = 0;
			int tmp = ab_idx;

			while (ab[ab_idx] + cd[cd_idx] == 0) {
				if (ab_idx >= idx)break;
				ab_cnt++;
				ab_idx++;
			}
			while (ab[tmp] + cd[cd_idx] == 0) {
				if (cd_idx < 0)break;
				cd_cnt++;
				cd_idx--;
			}

			answer += ab_cnt * cd_cnt;
		}
		else if (ab[ab_idx] + cd[cd_idx] < 0)ab_idx++;
		else cd_idx--;
	}

	cout << answer;
}