#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n1, n2, N;
vector<int> sum1;
vector<int> sum2;
vector<long long> sumA;
vector<long long> sumB;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cin >> n1;
	sum1.resize(n1+1);
	sum1[0] = 0;
	for (int i = 0; i < n1; i++) {
		cin >> sum1[i + 1];
		sum1[i + 1] += sum1[i];
	}

	for (int i = 0; i < n1 + 1; i++) {
		for (int j = 0; j < i; j++) {
			sumA.push_back(sum1[i] - sum1[j]);
		}
	}
	cin >> n2;
	sum2.resize(n2+1);
	sum2[0] = 0;
	for (int i = 0; i < n2; i++) {
		cin >> sum2[i + 1];
		sum2[i + 1] += sum2[i];
	}

	for (int i = 0; i < n2 + 1; i++) {
		for (int j = 0; j < i; j++) {
			sumB.push_back(sum2[i] - sum2[j]);
		}
	}

	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

	int l = 0, r = sumB.size() - 1;

	while (0 <= r && l < sumA.size()) {
		if (sumA[l] + sumB[r] > N)r--;
		else if (sumA[l] + sumB[r] < N)l++;
		else {
			long long tmpA = sumA[l];
			long long tmpB = sumB[r];
			long long cntA = 0;
			long long cntB = 0;

			while (l < sumA.size()&&tmpA == sumA[l]) {
				l++; cntA++;
			}
			while (r >= 0&&tmpB == sumB[r]) {
				r--; cntB++;
			}
			cnt += cntA * cntB;
		}
	}
	cout << cnt;
}