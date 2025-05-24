#include<iostream>
#include<vector>
using namespace std;

long long N;
vector<int> fibo;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	fibo.push_back(0);
	fibo.push_back(1);

	int cycle = 15 * 100000;

	for (int i = 2; i < cycle; i++)fibo.push_back((fibo[i - 2] + fibo[i - 1])%1000000);
	cout << fibo[N%cycle];
}