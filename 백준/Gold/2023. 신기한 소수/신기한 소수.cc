#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int f[] = { 2,3,5,7 };

bool isPrime(int num) {
	if (num < 2)return false;
	for (int i = 2; i <= sqrt(num); i++)if (num%i == 0)return false;
	return true;
}

void dfs(int prime, int depth) {
	if (depth == N) {
		cout << prime << "\n";
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		int tmp = prime * 10 + i;
		if (isPrime(tmp))dfs(tmp, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) {
		dfs(f[i], 1);
	}
}
