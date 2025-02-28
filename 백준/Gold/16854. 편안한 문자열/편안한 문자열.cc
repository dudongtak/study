#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const ull base = 131;  
string S;              
int n;                 

vector<int> p;

vector<vector<int>> st;
vector<int> log_table;

void buildRMQ() {
	int m = n + 1;
	log_table.resize(m + 1);
	for (int i = 2; i <= m; i++)
		log_table[i] = log_table[i / 2] + 1;

	int K = log_table[m] + 1;
	st.assign(m, vector<int>(K));
	for (int i = 0; i < m; i++)
		st[i][0] = p[i];

	for (int j = 1; (1 << j) <= m; j++) {
		for (int i = 0; i + (1 << j) - 1 < m; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int queryRMQ(int L, int R) {
	int j = log_table[R - L + 1];
	return min(st[L][j], st[R - (1 << j) + 1][j]);
}

vector<ull> hashS, powerS;

void buildHashS() {
	hashS.resize(n + 1, 0);
	powerS.resize(n + 1, 1);
	for (int i = 0; i < n; i++) {
		ull val = (S[i] == '(' ? 1ULL : 2ULL);
		hashS[i + 1] = hashS[i] * base + val;
		powerS[i + 1] = powerS[i] * base;
	}
}

ull getHashS(int l, int r) {
	return hashS[r + 1] - hashS[l] * powerS[r - l + 1];
}

string R;

void buildR() {
	R.resize(n);
	for (int i = 0; i < n; i++) {
		char c = S[n - 1 - i];
		R[i] = (c == '(' ? ')' : '(');
	}
}

vector<ull> hashR, powerR;

void buildHashR() {
	hashR.resize(n + 1, 0);
	powerR.resize(n + 1, 1);
	for (int i = 0; i < n; i++) {
		ull val = (R[i] == '(' ? 1ULL : 2ULL);
		hashR[i + 1] = hashR[i] * base + val;
		powerR[i + 1] = powerR[i] * base;
	}
}

ull getHashR(int l, int r) {
	return hashR[r + 1] - hashR[l] * powerR[r - l + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	n = S.size();

	p.resize(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + (S[i] == '(' ? 1 : -1);
	}
	buildRMQ();

	buildHashS();
	buildR();
	buildHashR();

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int len = j - i + 1;
			if (len % 2 == 1) continue;  

			if (p[j + 1] - p[i] != 0) continue;
			if (queryRMQ(i, j + 1) < p[i]) continue;

			int L = n - 1 - j, R_index = n - 1 - i;
			if (getHashS(i, j) == getHashR(L, R_index))
				ans++;
		}
	}

	cout << ans << "\n";
	return 0;
}
