#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string str;
vector<vector<int>> w_sum,b_sum;
int n, m, k;

bool changeColor(char s, char input, bool even) {
	if (even&&s == input)return false;
	else if (!even&&s != input)return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	w_sum.resize(n + 1, vector<int>(m + 1, 0));
	b_sum.resize(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			bool even = (i + j) % 2 == 0;

			w_sum[i][j] = w_sum[i][j - 1] + w_sum[i - 1][j] - w_sum[i - 1][j - 1] + changeColor('W', str[j - 1], even);
			b_sum[i][j] = b_sum[i][j - 1] + b_sum[i - 1][j] - b_sum[i - 1][j - 1] + changeColor('B', str[j - 1], even);
		}
	}

	int white = 4000001, black = 4000001;

	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			white = min(white, w_sum[i][j] - w_sum[i - k][j] - w_sum[i][j - k] + w_sum[i - k][j - k]);
			black = min(black, b_sum[i][j] - b_sum[i - k][j] - b_sum[i][j - k] + b_sum[i - k][j - k]);
		}
	}
	cout << min(white, black);
}